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

#include <sys/select.h>
#include <hid.h>
#include <log.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define SYSFS_HIDRAW_CLASS_PATH "/sys/class/hidraw"

void init_hid_device(struct st_hid_device *hid_device)
{
	int i;
	
	hid_device->num_interfaces = 0;
	
	for(i=0;i<HID_MAX_INTERFACES;i++)
		hid_device->interface_fd[i] = -1;
	
	hid_device->interface_fd_max = -1;
}

static int get_file_contents(const char *filename,char *buf, unsigned int buf_len)
{
	int fd,re;
	
	fd = open(filename,O_RDONLY);
	if(fd<0)
		return -1;
	
	re = read(fd,buf,buf_len);
	close(fd);
	
	if(re<0 || re>=buf_len)
		return -1;
	
	buf[re] = '\0';
	if(re>0 && buf[re-1]=='\n')
		buf[re-1] = '\0';
	
	return 0;
}

int lookup_hid_product(int lookup_mode,const char *manufacturer,const char *product,struct st_hid_device *hid_device)
{
	DIR *dh;
	struct dirent *entry;
	char buf[256],filename[PATH_MAX],symlink_filename[PATH_MAX];
	int re;
	
	if(manufacturer!=0)
		hid_device->num_interfaces = 0;

	// Open sys FS to lookup all HID devices
	dh = opendir(SYSFS_HIDRAW_CLASS_PATH);
	if(dh==0)
		return -1;
	
	while(entry = readdir(dh))
	{
		re = snprintf(filename,PATH_MAX,SYSFS_HIDRAW_CLASS_PATH "/%s",entry->d_name);
		if(re>=PATH_MAX)
		{
			closedir(dh);
			return -1;
		}
		
		if(entry->d_type!=DT_LNK)
			continue;
		
		re = readlink(filename,symlink_filename,PATH_MAX);
		if(re>0 && re<PATH_MAX)
		{
			buf[re] = '\0';
			
			if(manufacturer==0)
				info("Found HID device at /dev/%s",entry->d_name);
			
			// Read vendor name
			if(lookup_mode==LOOKUP_MODE_NAME)
				re = snprintf(filename,PATH_MAX,SYSFS_HIDRAW_CLASS_PATH "/%s/../../../../manufacturer",symlink_filename);
			else if(lookup_mode==LOOKUP_MODE_ID)
				re = snprintf(filename,PATH_MAX,SYSFS_HIDRAW_CLASS_PATH "/%s/../../../../idVendor",symlink_filename);
			
			if(re>=PATH_MAX)
			{
				closedir(dh);
				return -1;
			}
			
			
			if(get_file_contents(filename,buf,256)<0)
			{
				if(manufacturer==0)
					printf("  Manufacturer : Unknown\n");
				else
				{
					closedir(dh);
					return -1;
				}
			}
			else
			{
				if(manufacturer==0)
					printf("  Manufacturer : %s\n",buf);
				else if(strcmp(buf,manufacturer)!=0)
					continue;
			}
			
			// Read product name
			if(lookup_mode==LOOKUP_MODE_NAME)
				re = snprintf(filename,PATH_MAX,SYSFS_HIDRAW_CLASS_PATH "/%s/../../../../product",symlink_filename);
			else if(lookup_mode==LOOKUP_MODE_ID)
				re = snprintf(filename,PATH_MAX,SYSFS_HIDRAW_CLASS_PATH "/%s/../../../../idProduct",symlink_filename);
			
			if(re>=PATH_MAX)
			{
				closedir(dh);
				return -1;
			}
			
			if(get_file_contents(filename,buf,256)<0)
			{
				if(manufacturer==0)
				{
					printf("  Product name : Unknown\n\n");
					continue;
				}
				else
				{
					closedir(dh);
					return -1;
				}
			}
			
			if(manufacturer==0)
				printf("  Product name : %s\n\n",buf);
			else if(strcmp(buf,product)==0)
			{
				if(hid_device->num_interfaces>=HID_MAX_INTERFACES)
				{
					closedir(dh);
					return -2;
				}
				
				// We found one interface of HID device
				re = snprintf(hid_device->interface_device[hid_device->num_interfaces],PATH_MAX,"/dev/%s",entry->d_name);
				if(re>=PATH_MAX)
				{
					closedir(dh);
					return -1;
				}
				
				hid_device->num_interfaces++;
			}
		}
	}
	
	closedir(dh);
	
	if(manufacturer==0)
		return 0;
	
	if(hid_device->num_interfaces>0)
		return 0;
	return -1;
}

int open_hid_device(struct st_hid_device *hid_device)
{
	int i;
	
	hid_device->interface_fd_max = -1;
	for(i=0;i<hid_device->num_interfaces;i++)
	{
		hid_device->interface_fd[i] = open(hid_device->interface_device[i],O_RDONLY);
		if(hid_device->interface_fd[i]<0)
		{
			close_hid_device(hid_device);
			return -1;
		}
		
		if(hid_device->interface_fd[i]>hid_device->interface_fd_max)
			hid_device->interface_fd_max = hid_device->interface_fd[i];
		
		
		info("Opened HID interface on %s",hid_device->interface_device[i]);
	}
	
	return 0;
}

int close_hid_device(struct st_hid_device *hid_device)
{
	int i,exit_code;
	
	exit_code = 0;
	for(i=0;i<hid_device->num_interfaces;i++)
	{
		if(hid_device->interface_device[i]>=0)
		{
			if(close(hid_device->interface_fd[i])<0)
				exit_code = -1;
			else
				hid_device->interface_fd[i] = -1;
		}
	}
	
	return exit_code;
}

int read_hid_event(struct st_hid_device *hid_device,char *event,unsigned int *length)
{
	fd_set rfds;
	int i,re;
	
	FD_ZERO(&rfds);
	
	for(i=0;i<hid_device->interface_fd[i];i++)
		FD_SET(hid_device->interface_fd[i],&rfds);
	
	re = select(hid_device->interface_fd_max+1,&rfds,NULL,NULL,NULL);
	if(re<0)
		return -1;
	
	for(i=0;i<hid_device->interface_fd[i];i++)
	{
		if(FD_ISSET(hid_device->interface_fd[i],&rfds))
		{
			re = read(hid_device->interface_fd[i],event,*length);
			if(re<=0)
				return -1;

			*length = re;
		}
	}
	
	
	return 0;
}
