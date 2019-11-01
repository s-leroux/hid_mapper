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

/*** Very basic logging facility **/

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum LogLevel {
	LOG_ERROR,
	LOG_WARN,
	LOG_INFO,
} LogLevel;

extern int currentLogLevel;

void logmsg(LogLevel severity, const char* fmt, va_list args);
//void logmsg(LogLevel severity, const char* fmt, ...);

void info(const char* fmt, ...);
void warn(const char* fmt, ...);
void error(const char* fmt, ...);

#ifdef __cplusplus
} // extern "C"
#endif

