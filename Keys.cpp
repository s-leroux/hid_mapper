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

#include <Keys.h>
#include <keys_definition.h>

#include <string.h>

int Keys::Lookup(const char *key_name)
{
	int cmp,begin,middle,end;
	begin = 0;
	end = keys_array_size-1;
	do
	{
		middle = (end+begin)/2;
		cmp = strcmp(keys_char[middle],key_name);
		if(cmp==0)
			return keys_int[middle];
		if(cmp<0)
			begin=middle+1;
		else
			end=middle-1;
	}while(begin<=end);
	return -1;
}

int Keys::GetMaxKey(void)
{
	int max = keys_int[0];
	for(int i=1;i<keys_array_size;i++)
		if(keys_int[i]>max)
			max = keys_int[i];
	
		return max;
}
