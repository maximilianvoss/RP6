CC=/usr/local/bin/avr-gcc
OBJCOPY=/usr/local/bin/avr-objcopy
CFLAGS=-Wall -Os -mmcu=atmega32 -I../../RP6Library -L../../RP6Library/build -lrp6library -c
OBJFLAGS=-O ihex -j .text -j data
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.elf)
EXECUTABLES=$(SOURCES:.c=.hex)

all: clean $(SOURCES) $(EXECUTABLES)

$(EXECUTABLES): $(OBJECTS)
	$(OBJCOPY) $(OBJFLAGS) $(OBJECTS) $@

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)
	rm -f $(OBJECTS)

