CC=/usr/local/bin/avr-gcc
AR=/usr/local/bin/avr-ar
CFLAGS=-Wall -O2 -mmcu=atmega32 -I.. -c
ARFLAGS=-rcs
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../build/engine.a

all: clean $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE)
	rm -f $(SOURCES:.c=.o)