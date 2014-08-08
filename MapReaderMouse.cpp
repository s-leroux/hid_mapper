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

#include <MapReaderMouse.h>
#include <Exception.h>
#include <config.h>

#include <stdio.h>
#include <stdlib.h>
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

void MapReaderMouse::LoadMap(const char *filename,EventMapping *map)
{
	FILE *f = 0;
	int i,event_length,line,imove,iaction_type;
	char buf[MAP_LINE_MAXLENGTH],event[EVENT_MAXLENGTH],mask[EVENT_MAXLENGTH],action_type[MOUSE_ACTION_MAXLENGTH+1],move[MOUSE_MOVE_MAXLENGTH+1],error[256];
	char *ptr;
	
	try
	{
		f = fopen(filename,"r");
		if(!f)
			throw Exception("MapReaderMouse","Unable to open map file");
		
		line = 1;
		while(fgets(buf,MAP_LINE_MAXLENGTH,f))
		{
			memset(mask,0,EVENT_MAXLENGTH);
			
			ptr = buf;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]=='#' || ptr[0]=='\n')
				continue; // Skip comments
			
			// Read hexadecimal event description
			i = 0;
			while(i<EVENT_MAXLENGTH && ((isxdigit(ptr[0]) && isxdigit(ptr[1])) || (ptr[0]=='X' && ptr[1]=='X')))
			{
				if(ptr[0]=='X' && ptr[1]=='X')
					mask[i] = 0xFF;
				else
					event[i] = (hex_to_int(ptr[0])<<4)|hex_to_int(ptr[1]);
				
				ptr+=2;
				i++;
			}
			
			if(i==EVENT_MAXLENGTH)
			{
				sprintf(error,"Event description is too large at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			event_length = i;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]!=':')
			{
				sprintf(error,"Expected ':' at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			ptr++;
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			// Read action type
			i = 0;
			while(i<MOUSE_ACTION_MAXLENGTH && ptr[i]!='\0' && ptr[i]!='\n' && ptr[i]!=' ' && ptr[i]!=':')
				action_type[i] = ptr[i++];
			
			if(i==MOUSE_ACTION_MAXLENGTH)
			{
				sprintf(error,"Mouse action is too long at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			action_type[i] = '\0';
			
			ptr += i;
			
			if(strcmp(action_type,"REL_X")==0)
				iaction_type = EVENT_TYPE_MOUSE_X;
			else if(strcmp(action_type,"REL_Y")==0)
				iaction_type = EVENT_TYPE_MOUSE_Y;
			else
			{
				sprintf(error,"Unknown mouse action at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]!=':')
			{
				sprintf(error,"Expected ':' at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			ptr++;
			
			// Read movement
			i = 0;
			while(i<MOUSE_MOVE_MAXLENGTH && ptr[i]!='\0' && ptr[i]!='\n' && ptr[i]!=' ')
				move[i] = ptr[i++];
			
			if(i==MOUSE_MOVE_MAXLENGTH)
			{
				sprintf(error,"Movement is too long at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			move[i] = '\0';
			
			ptr += i;
			
			imove = atoi(move);
			if(imove==0)
			{
				sprintf(error,"Invalid mouse movement at line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			// Skip spaces if any
			while(ptr[0]==' ')
				ptr++;
			
			if(ptr[0]!='\n' && ptr[0]!='\0' && ptr[0]!='#')
			{
				sprintf(error,"Garbage at end of line %d",line);
				throw Exception("MapReaderMouse",error);
			}
			
			map->AddEvent(iaction_type,event,mask,event_length,imove);
			
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
