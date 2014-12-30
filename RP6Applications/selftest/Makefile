CC=/usr/local/bin/avr-gcc
OBJCOPY=/usr/local/bin/avr-objcopy
CFLAGS=-c -mmcu=atmega32 -I../../RP6Library -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -Wall -Wstrict-prototypes -std=gnu99
LDFLAGS=-L../../RP6Library/build -luart -lcore -lscheduler -lengine -lpowermgmt
ALLFLAGS=-mmcu=atmega32 -I../../RP6Library -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -Wall -Wstrict-prototypes -std=gnu99
OBJFLAGS=-O ihex -R .eeprom
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=selftest.elf
HEXFILE=selftest.hex

all: clean $(SOURCES) $(EXECUTABLE) $(HEXFILE)

$(HEXFILE): $(EXECUTABLE)
	$(OBJCOPY) $(OBJFLAGS) $< $@
	scp $@ voss@vmware:~/data/

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(ALLFLAGS) $(OBJECTS) --output $@ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(HEXFILE)
	rm -f $(EXECUTABLE)
	rm -f $(SOURCES:.c=.o)
