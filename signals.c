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

#include <signals.h>
#include <hid.h>
#include <uinput_device.h>

#include <stdio.h>
#include <stdlib.h>

void sigterm_handler(int signum)
{
	int exit_code = 0;
	
	printf("Caught SIG_TERM, exiting...\n");
	
	// Destroy event device
	if(uinput_fd>=0 && destroy_device(uinput_fd)<0)
	{
		fprintf(stderr,"Unable to destroy event device\n");
		exit_code = EXIT_FAILURE;
	}
	
	// Close HID device
	if(close_hid_device(&hid_device)<0)
	{
		fprintf(stderr,"Unable to close HID device\n");
		exit_code = EXIT_FAILURE;
	}
	
	exit(exit_code);
}
