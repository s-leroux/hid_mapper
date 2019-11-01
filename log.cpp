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
 * Author: Sylvain Leroux <sylvain@chicoree.fr>
 */

#include <stdio.h>
#include <log.h>

int currentLogLevel = 99; /* log all */

const char* headers[] = {
	"INFO",
	"WARN",
	"ERRO",
};

void logmsg(LogLevel severity, const char* fmt, va_list args) {
	if (severity < currentLogLevel) {
		vfprintf(stderr, fmt, args);
		putc('\n', stderr);
	}
}

void logmsg(LogLevel severity, const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	logmsg(severity, fmt, args);
	va_end(args);

}

void info(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	logmsg(LOG_INFO, fmt, args);
	va_end(args);
}

void warn(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	logmsg(LOG_WARN, fmt, args);
	va_end(args);
}

void error(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	logmsg(LOG_ERROR, fmt, args);
	va_end(args);
}

