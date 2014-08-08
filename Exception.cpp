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

#include <Exception.h>

#include <string.h>
#include <stdio.h>

Exception::Exception(const char *context,const char *error)
{
	this->context = new char[strlen(context)+1];
	strcpy(this->context,context);
	
	this->error = new char[strlen(error)+1];
	strcpy(this->error,error);
}

Exception::Exception(const Exception &e)
{
	this->context = new char[strlen(e.context)+1];
	strcpy(this->context,e.context);
	
	this->error = new char[strlen(e.error)+1];
	strcpy(this->error,e.error);
}

Exception::~Exception(void)
{
	delete[] context;
	delete[] error;
}

Exception &Exception::operator=(const Exception &e)
{
	if(this==&e)
		return *this;
	
	if(this->context)
		delete[] this->context;
	this->context = new char[strlen(e.context)+1];
	strcpy(this->context,e.context);
	
	if(this->error)
		delete[] this->error;
	this->error = new char[strlen(e.error)+1];
	strcpy(this->error,e.error);
	
	return *this;

}

void Exception::Print(void)
{
	fprintf(stderr,"[ %s ] %s\n",context,error);
}
