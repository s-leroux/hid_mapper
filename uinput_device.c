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

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/uinput.h>

int setup_device(int key_max)
{
	int uinput_fd;
	int i;
	struct uinput_user_dev uidev;
	
	uinput_fd = open("/dev/uinput",O_WRONLY|O_NONBLOCK);
	if(uinput_fd<0)
	{
		uinput_fd = open("/dev/input/uinput",O_WRONLY|O_NONBLOCK);
		if(uinput_fd<0)
			return -1;
	}

	if(ioctl(uinput_fd,UI_SET_EVBIT,EV_KEY)<0)
		return -1;
	
	if(ioctl(uinput_fd,UI_SET_EVBIT,EV_REL)<0)
		return -1;
	
	if(ioctl(uinput_fd,UI_SET_RELBIT,REL_X)<0)
		return -1;
	
	if(ioctl(uinput_fd,UI_SET_RELBIT,REL_Y)<0)
		return -1;
	
	for(i=0;i<key_max;i++)
		if(ioctl(uinput_fd,UI_SET_KEYBIT,i)<0)
			return -1;
	
	// Set device properties
	memset(&uidev,0,sizeof(uidev));
	snprintf(uidev.name,UINPUT_MAX_NAME_SIZE,"Generic USB input mapper");
	uidev.id.bustype = BUS_USB;
	uidev.id.vendor  = 0x1;
	uidev.id.product = 0x1;
	uidev.id.version = 1;

	if(write(uinput_fd, &uidev, sizeof(uidev)) < 0)
		return -1;

	if(ioctl(uinput_fd, UI_DEV_CREATE) < 0)
		return -1;
	
	return uinput_fd;
}

int destroy_device(int uinput_fd)
{
	if(ioctl(uinput_fd,UI_DEV_DESTROY)<0)
		return -1;

	return close(uinput_fd);
}

void send_key_down_event(int uinput_fd,int code)
{
	struct input_event ev;
	
	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_KEY;
	ev.code = code;
	ev.value = 1;
	if(write(uinput_fd,&ev,sizeof(struct input_event))<0)
		return;

	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_SYN;
	if(write(uinput_fd, &ev, sizeof(struct input_event)) < 0)
		return;
}

void send_key_up_event(int uinput_fd,int code)
{
	struct input_event ev;
	
	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_KEY;
	ev.code = code;
	ev.value = 0;
	if(write(uinput_fd,&ev,sizeof(struct input_event))<0)
		return;

	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_SYN;
	if(write(uinput_fd, &ev, sizeof(struct input_event)) < 0)
		return;
}

void send_mouse_X_event(int uinput_fd,int pixels)
{
	struct input_event ev;
	
	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_REL;
	ev.code = REL_X;
	ev.value = pixels;
	if(write(uinput_fd,&ev,sizeof(struct input_event))<0)
		return;

	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_SYN;
	ev.code = SYN_REPORT;
	if(write(uinput_fd, &ev, sizeof(struct input_event)) < 0)
		return;
}

void send_mouse_Y_event(int uinput_fd,int pixels)
{
	struct input_event ev;
	
	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_REL;
	ev.code = REL_Y;
	ev.value = pixels;
	if(write(uinput_fd,&ev,sizeof(struct input_event))<0)
		return;

	memset(&ev,0,sizeof(struct input_event));
	ev.type = EV_SYN;
	ev.code = SYN_REPORT;
	if(write(uinput_fd, &ev, sizeof(struct input_event)) < 0)
		return;
}
