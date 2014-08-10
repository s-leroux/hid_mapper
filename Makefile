#
# This file is part of hid_mapper.
# 
# hid_mapper is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# hid_mapper is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with hid_mapper. If not, see <http://www.gnu.org/licenses/>.
# 
# Author: Thibault Kummer <bob@coldsource.net>
#         Sylvain Leroux <sylvain@chicoree.fr>
# 

SOURCES=main.cpp uinput_device.c hid.c signals.c keys_definition.cpp EventMapping.cpp Keys.cpp \
        Exception.cpp MapReader.cpp MapReaderMouse.cpp log.cpp
OBJS=main.o uinput_device.o hid.o signals.o keys_definition.o EventMapping.o Keys.o \
     Exception.o MapReader.o MapReaderMouse.o log.o
CPPFLAGS=-Iinclude
CFLAGS=-Iinclude
LDFLAGS=
EXEC=hid_mapper
VERSION=2.1.0

all: $(OBJS)
	g++ $(LDFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	g++ -c $(CPPFLAGS) $<

%.o: %.c
	gcc -c $(CFLAGS) $<

deb: all
	rm -rf package/
	mkdir package/
	cp -r DEBIAN/ package/DEBIAN/

	install -D scripts/hid_mapper.rc-d package/etc/init.d/hid_mapper
	install -D scripts/hid_mapper.default package/etc/default/hid_mapper
	install -D $(EXEC) package/usr/bin/$(EXEC)
	
	mkdir -p package/usr/share/hid-mapper/
	cp -dr --no-preserve=ownership maps package/usr/share/hid-mapper/

	dpkg-deb --build package hid-mapper-$(VERSION)-amd64.deb

clean:
	rm -f *.o
	rm -f $(EXEC)
	rm -rf package/

depend:
	makedepend -Y $(CPPFLAGS) $(SOURCES) 2>/dev/null

# DO NOT DELETE

main.o: include/uinput_device.h include/hid.h include/config.h
main.o: include/signals.h include/EventMapping.h include/MapReader.h
main.o: include/MapReaderMouse.h include/Exception.h include/Keys.h
hid.o: include/hid.h include/config.h
signals.o: include/signals.h include/hid.h include/config.h
signals.o: include/uinput_device.h
keys_definition.o: include/keys_definition.h
EventMapping.o: include/EventMapping.h include/config.h
Keys.o: include/Keys.h include/keys_definition.h
Exception.o: include/Exception.h
MapReader.o: include/MapReader.h include/EventMapping.h include/config.h
MapReader.o: include/Keys.h include/Exception.h
MapReaderMouse.o: include/MapReaderMouse.h include/EventMapping.h
MapReaderMouse.o: include/config.h include/Exception.h
