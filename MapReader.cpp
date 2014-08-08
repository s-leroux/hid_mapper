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

#include <MapReader.h>
#include <Keys.h>
#include <Exception.h>
#include <config.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int hex_to_int(char c)
{
	c = tolower(c);
	if(c>='0' && c<='9')
		return c-'0';
	if(c>='a' && c<='f')
		return 0x0A+(c-'a');
	return -1;
}

void MapReader::LoadMap(const char *filename,EventMapping *map)
{
	FILE *f = 0;
	int i,event_length,event_type,line,key;
	char buf[MAP_LINE_MAXLENGTH],event[EVENT_MAXLENGTH],mask[EVENT_MAXLENGTH],key_name[KEY_NAME_MAXLENGTH+1],error[256];
	char *ptr;
	
	memset(mask,0,EVENT_MAXLENGTH);
	
	try
	{
		f = fopen(filename,"r");
		if(!f)
			throw Exception("MapReader","Unable to open map file");
		
		line = 1;
		while(fgets(buf,MAP_LINE_MAXLENGTH,f))
		{
			ptr = buf;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]=='#' || ptr[0]=='\n')
				continue; // Skip comments
			
			// Read hexadecimal event description
			i = 0;
			while(i<EVENT_MAXLENGTH && isxdigit(ptr[0]) && isxdigit(ptr[1]))
			{
				event[i] = (hex_to_int(ptr[0])<<4)|hex_to_int(ptr[1]);
				ptr+=2;
				i++;
			}
			
			if(i==EVENT_MAXLENGTH)
			{
				sprintf(error,"Event description is too large at line %d",line);
				throw Exception("MapReader",error);
			}
			
			event_length = i;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]!=':')
			{
				sprintf(error,"Expected ':' at line %d",line);
				throw Exception("MapReader",error);
			}
			
			ptr++;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			i = 0;
			while(i<KEY_NAME_MAXLENGTH && ptr[i]!='\0' && ptr[i]!='\n' && ptr[i]!=' ')
				key_name[i] = ptr[i++];
			
			if(i==KEY_NAME_MAXLENGTH)
			{
				sprintf(error,"Key name is too long at line %d",line);
				throw Exception("MapReader",error);
			}
			
			key_name[i] = '\0';
			
			ptr += i;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]!='\n' && ptr[0]!='\0' && ptr[0]!='#')
			{
				sprintf(error,"Garbage at end of line %d",line);
				throw Exception("MapReader",error);
			}
			
			if(strncmp(key_name,"CORE::",6)==0)
			{
				event_type = EVENT_TYPE_CORE;
				if(strcmp(key_name+6,"LAST_KEY")==0)
					key = EVENT_CORE_LAST_KEY;
				else
				{
					sprintf(error,"Unknown core event name at line %d",line);
					throw Exception("MapReader",error);
				}
			}
			else
			{
				event_type = EVENT_TYPE_KEYBOARD;
				key = Keys::Lookup(key_name);
				if(key<0)
				{
					sprintf(error,"Unknown key name at line %d",line);
					throw Exception("MapReader",error);
				}
			}
			
			map->AddEvent(event_type,event,mask,event_length,key);
			
			line++;
		}
	}
	catch(Exception &e)
	{
		if(f)
			fclose(f);
		
		throw e;
	}
	
	fclose(f);
}
