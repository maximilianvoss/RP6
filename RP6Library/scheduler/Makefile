CC=/usr/local/bin/avr-gcc
AR=/usr/local/bin/avr-ar
CFLAGS=-c -mmcu=atmega32 -I.. -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -Wall -Wstrict-prototypes -std=gnu99
ARFLAGS=-rcs
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/libscheduler.a

all: clean $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SOURCES:.c=.o)