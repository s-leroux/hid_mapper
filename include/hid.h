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

#ifndef _HID_H_
#define _HID_H_

#include <config.h>
#include <linux/limits.h>

#define LOOKUP_MODE_ID     1
#define LOOKUP_MODE_NAME   2

struct st_hid_device
{
	int num_interfaces;
	char interface_device[HID_MAX_INTERFACES][PATH_MAX];
	int interface_fd[HID_MAX_INTERFACES];
	int interface_fd_max;
};

void init_hid_device(struct st_hid_device *hid_device);

int lookup_hid_product(int lookup_mode,const char *manufacturer,const char *product,struct st_hid_device *hid_device);

int open_hid_device(struct st_hid_device *hid_device);
int close_hid_device(struct st_hid_device *hid_device);
int read_hid_event(struct st_hid_device *hid_device,char *event,unsigned int *length);

#endif
