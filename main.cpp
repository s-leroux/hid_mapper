/*
 * This file is part of hid_mapper.
 * 
 * hid_mapper is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * hid_mapper is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with hid_mapper. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author: Thibault Kummer <bob@coldsource.net>
 */

extern "C"
{
	#include <uinput_device.h>
	#include <hid.h>
	#include <signals.h>
}

#include <EventMapping.h>
#include <MapReader.h>
#include <MapReaderMouse.h>
#include <Exception.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/limits.h>

#include <Keys.h>

int uinput_fd = -1;
struct st_hid_device hid_device;

#define MODE_LEARN    1
#define MODE_MAP      2

static void print_usage(void)
{
	printf("Usage :\n");
	printf("  hid_mapper --list-devices [ --lookup-id ]\n");
	printf("  hid_mapper [ --lookup-id ] [ --disable-repetition ] --manufacturer <manufacturer> --product <product name> [ --map <map file>] [ --map-mouse <map file> ]\n");
	printf("  hid_mapper [ --lookup-id ] --learn --manufacturer <manufacturer> --product <product name>\n");
}

int main(int argc,char **argv)
{
	char manufacturer[256],product[256];
	const char *map_filename = 0,*map_mouse_filename = 0;
	int mode = MODE_MAP;
	int lookup_mode = LOOKUP_MODE_NAME;
	int wait = -1;
	bool disable_repetition = false;
	
	// Check we are root
	uid_t uid;
	uid = geteuid();
	if(uid!=0)
	{
		fprintf(stderr,"hid_mapper must be run as root\n");
		return EXIT_FAILURE;
	}
	
	// Init hid_device
	init_hid_device(&hid_device);
	
	// Setup signal handler
	signal(SIGTERM,sigterm_handler);
	signal(SIGINT,sigterm_handler);
	
	if(argc==1)
	{
		print_usage();
		return -1;
	}
	
	if(argc==2 && strcmp(argv[1],"--list-devices")==0)
		return lookup_hid_product(LOOKUP_MODE_NAME,0,0,0);
	
	if(argc==3 && strcmp(argv[1],"--list-devices")==0 && strcmp(argv[2],"--lookup-id")==0)
		return lookup_hid_product(LOOKUP_MODE_ID,0,0,0);
	
	manufacturer[0] = '\0';
	product[0] = '\0';
	if(argc>=5)
	{
		for(int i=1;i<argc;i++)
		{
			if(strcmp(argv[i],"--learn")==0)
				mode = MODE_LEARN;
			else if(strcmp(argv[i],"--lookup-id")==0)
				lookup_mode = LOOKUP_MODE_ID;
			else if(strcmp(argv[i],"--disable-repetition")==0)
				disable_repetition = true;
		}
		
		for(int i=1;i<argc-1;i++)
		{
			if(strcmp(argv[i],"--manufacturer")==0)
			{
				strcpy(manufacturer,argv[i+1]);
				i++;
			}
			else if(strcmp(argv[i],"--product")==0)
			{
				strcpy(product,argv[i+1]);
				i++;
			}
			else if(strcmp(argv[i],"--map")==0)
			{
				map_filename = argv[i+1];
				i++;
			}
			else if(strcmp(argv[i],"--map-mouse")==0)
			{
				map_mouse_filename = argv[i+1];
				i++;
			}
			else if(strcmp(argv[i],"--wait-device")==0)
			{
				wait = atoi(argv[i+1]);
				i++;
			}
		}
	}
	
	if(manufacturer[0]=='\0' && product[0]=='\0')
	{
		print_usage();
		return -1;
	}
	
	if(mode==MODE_MAP && map_filename==0 && map_mouse_filename==0)
	{
		print_usage();
		return -1;
	}
	
	if(wait==0)
	{
		print_usage();
		return -1;
	}
	
	// Load map file
	EventMapping *map = new EventMapping();
	
	if(mode==MODE_MAP)
	{
		if(map_filename!=0)
		{
			try
			{
				MapReader::LoadMap(map_filename,map);
			}
			catch(Exception e)
			{
				fprintf(stderr,"Error loading map file\n");
				e.Print();
				return EXIT_FAILURE;
			}
			
			printf("Loaded map file %s\n",map_filename);
		}
		
		if(map_mouse_filename!=0)
		{
			try
			{
				MapReaderMouse::LoadMap(map_mouse_filename,map);
			}
			catch(Exception e)
			{
				fprintf(stderr,"Error loading mouse map file\n");
				e.Print();
				return EXIT_FAILURE;
			}
			
			printf("Loaded mouse map file %s\n",map_mouse_filename);
		}
	}
	
	// Lookup for specified HID device
	int re,max_hid_fd;
	
	if(wait>0)
		printf("Waiting device for %d second(s)\n",wait);
	
	while(true)
	{
		re = lookup_hid_product(lookup_mode,manufacturer,product,&hid_device);
		
		if(re>=0 || wait<=0)
			break;
		
		wait--;
		sleep(1);
	}
	
	if(re<0)
	{
		fprintf(stderr,"Unable to find specified HID device\n");
		return EXIT_FAILURE;
	}
		
	if(wait!=-1)
	{
		re = lookup_hid_product(lookup_mode,manufacturer,product,&hid_device);
	}
	else
	{
		re = lookup_hid_product(lookup_mode,manufacturer,product,&hid_device);
		
	}
	
	printf("Found HID device\n");
	
	// HID
	re = open_hid_device(&hid_device);
	if(re<0)
	{
		fprintf(stderr,"Unable to open HID device\n");
		return EXIT_FAILURE;
	}
	
	// Setup event device
	if(mode==MODE_MAP)
	{
		uinput_fd = setup_device(Keys::GetMaxKey());
		if(uinput_fd==-1)
		{
			fprintf(stderr,"Unable to setup event device\n");
			return EXIT_FAILURE;
		}
		
		printf("Generic USB mapper driver setup\n");
	}
	
	
	LinkedList<event_mapping> *event_map_list;
	const event_mapping *event_map;
	unsigned int event_length;
	char event[EVENT_MAXLENGTH];
	int last_key_down = 0, last_key_code = 0;
	
	while(1)
	{
		event_length = EVENT_MAXLENGTH;
		re = read_hid_event(&hid_device,event,&event_length);
		if(re<0)
		{
			fprintf(stderr,"Error reading HID event\n");
			continue;
		}
		
		if(mode==MODE_LEARN)
		{
			for(int i=0;i<event_length;i++)
				printf("%02x ",(unsigned char)event[i]);
			printf("\n");
		}
		else
		{
			if(last_key_down!=0)
			{
				send_key_up_event(uinput_fd,last_key_down);
				last_key_down = 0;
			}
			else
			{
				event_map_list = map->LookupEvent(event,event_length);
				event_map_list->StartEnum();
				while(event_map = event_map_list->Enum())
				{
					switch(event_map->type)
					{
						case EVENT_TYPE_KEYBOARD:
							send_key_down_event(uinput_fd,event_map->value);
							last_key_code = event_map->value;
							if(disable_repetition)
								send_key_up_event(uinput_fd,last_key_code);
							else
								last_key_down = last_key_code;
							break;
						
						case EVENT_TYPE_MOUSE_X:
							send_mouse_X_event(uinput_fd,event_map->value);
							break;
						
						case EVENT_TYPE_MOUSE_Y:
							send_mouse_Y_event(uinput_fd,event_map->value);
							break;
						
						case EVENT_TYPE_CORE:
							switch(event_map->value)
							{
								case EVENT_CORE_LAST_KEY:
									if(!last_key_code)
										break;
									
									send_key_down_event(uinput_fd,last_key_code);
									if(disable_repetition)
										send_key_up_event(uinput_fd,last_key_code);
									else
										last_key_down = last_key_code;
									
									break;
							}
							break;
					}
				}
			}
		}
	}

	return 0;
}
