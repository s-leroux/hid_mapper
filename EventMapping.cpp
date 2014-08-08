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

#include <EventMapping.h>

#include <string.h>

EventMapping::EventMapping(void)
{
	for(int i=0;i<EVENT_MAXLENGTH;i++)
	{
		map_hash[i] = 0;
		map_hash_size[i] = 0;
	}
	
	event_list = new LinkedList<event_mapping>;
	
	enum_current_hash_size = 0;
	enum_current_position = -1;
}

EventMapping::~EventMapping(void)
{
	for(int i=0;i<EVENT_MAXLENGTH;i++)
		if(map_hash)
			delete[] map_hash[i];
	
	delete event_list;
}

bool EventMapping::AddEvent(int type,const void *event,const void *mask,unsigned int length,int value)
{
	if(length==0 || length>EVENT_MAXLENGTH)
		return false;
	
	int newpos = map_hash_size[length-1];
	
	event_mapping *new_map = new event_mapping[map_hash_size[length-1]+1];
	
	memcpy(new_map,map_hash[length-1],newpos*sizeof(event_mapping));
	memcpy(new_map+newpos+1,map_hash[length-1]+newpos,(map_hash_size[length-1]-newpos)*sizeof(event_mapping));
	
	new_map[newpos].type = type;
	
	new_map[newpos].length = length;
	memcpy(new_map[newpos].event,event,length);
	memcpy(new_map[newpos].mask,mask,length);
	new_map[newpos].value = value;
	
	if(map_hash[length-1])
		delete[] map_hash[length-1];
	
	map_hash[length-1] = new_map;
	map_hash_size[length-1]++;
	
	return true;
}

LinkedList<event_mapping> *EventMapping::LookupEvent(const void *event,unsigned int event_length)
{
	event_list->Reset();
	
	if(event_length==0 || event_length>EVENT_MAXLENGTH)
		return event_list;
	
	if(map_hash_size[event_length-1]==0)
		return event_list;
	
	int i,j;
	for(i=0;i<map_hash_size[event_length-1];i++)
	{
		for(j=0;j<event_length;j++)
		{
			if((unsigned char)map_hash[event_length-1][i].mask[j]!=0xFF && map_hash[event_length-1][i].event[j]!=((char *)event)[j])
				break;
		}
		
		if(j==event_length)
			event_list->AddItem(&map_hash[event_length-1][i]);
	}
	
	return event_list;
}

void EventMapping::EnumReset(void)
{
	enum_current_hash_size = 0;
	enum_current_position = -1;
}

const event_mapping *EventMapping::EnumEvent(void)
{
	if(enum_current_hash_size>=EVENT_MAXLENGTH)
		return 0;
	
	for(;enum_current_hash_size<EVENT_MAXLENGTH;enum_current_hash_size++)
	{
		if(enum_current_position+1>=map_hash_size[enum_current_hash_size])
		{
			enum_current_position = -1;
			continue;
		}
		
		enum_current_position++;
		return &map_hash[enum_current_hash_size][enum_current_position];
	}
	
	return 0;
}
