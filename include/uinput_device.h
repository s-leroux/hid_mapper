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

#ifndef _UINPUT_H_
#define _UINPUT_H_

int setup_device(int key_max);
int destroy_device(int uinput_fd);

int register_key(int uinput_fd,int code);

void send_key_down_event(int uinput_fd,int code);
void send_key_up_event(int uinput_fd,int code);
void send_mouse_X_event(int uinput_fd,int pixels);
void send_mouse_Y_event(int uinput_fd,int pixels);

#endif
