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

#ifndef _EVENTMAPPING_H_
#define _EVENTMAPPING_H_

#define EVENT_TYPE_KEYBOARD              0x01
#define EVENT_TYPE_MOUSE_X               0x02
#define EVENT_TYPE_MOUSE_Y               0x03
#define EVENT_TYPE_CORE                  0x04

#define EVENT_CORE_LAST_KEY              0x01

#include <config.h>
#include <LinkedList.h>

struct event_mapping
{
	int type;
	int length;
	char event[EVENT_MAXLENGTH];
	char mask[EVENT_MAXLENGTH];
	int value;
};

class EventMapping
{
private:
	event_mapping *map_hash[EVENT_MAXLENGTH];
	unsigned int map_hash_size[EVENT_MAXLENGTH];
	
	LinkedList<event_mapping> *event_list;
	
	int enum_current_hash_size;
	int enum_current_position;
	
public:
	EventMapping(void);
	~EventMapping(void);
	
	bool AddEvent(int type,const void *event,const void *mask,unsigned int length,int value);
	LinkedList<event_mapping> *LookupEvent(const void *event,unsigned int event_length);
	
	void EnumReset(void);
	const event_mapping *EnumEvent(void);
};

#endif
