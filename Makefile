SOURCES=main.cpp uinput_device.c hid.c signals.c keys_definition.cpp EventMapping.cpp Keys.cpp \
        Exception.cpp MapReader.cpp MapReaderMouse.cpp
OBJS=main.o uinput_device.o hid.o signals.o keys_definition.o EventMapping.o Keys.o \
     Exception.o MapReader.o MapReaderMouse.o
CPPFLAGS=-Iinclude
CFLAGS=-Iinclude
LDFLAGS=
EXEC=hid_mapper
VERSION=1.0

all: $(OBJS)
	g++ $(LDFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	g++ -c $(CPPFLAGS) $<

%.o: %.c
	gcc -c $(CFLAGS) $<

deb:
	cp $(EXEC) package/usr/bin
	dpkg --build package rtse-$(VERSION)-amd64.deb

clean:
	rm -f *.o
	rm -f $(EXEC)

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
