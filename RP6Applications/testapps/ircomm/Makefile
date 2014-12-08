CC=/usr/local/bin/avr-gcc
OBJCOPY=/usr/local/bin/avr-objcopy
CFLAGS=-c -mmcu=atmega32 -I../../../RP6Library -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -Wall -Wstrict-prototypes -std=gnu99
LDFLAGS=-L../../../RP6Library/build -luart -lcore -lircomm -lircommAcs -lscheduler
ALLFLAGS=-mmcu=atmega32 -I../../../RP6Library -gdwarf-2 -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -Wall -Wstrict-prototypes -std=gnu99
OBJFLAGS=-O ihex -R .eeprom
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLES=$(SOURCES:.c=.elf)
HEXFILES=$(SOURCES:.c=.hex)

all: clean $(SOURCES) $(EXECUTABLES) $(HEXFILES)

$(HEXFILES): $(EXECUTABLES)
	$(OBJCOPY) $(OBJFLAGS) $< $@
	scp $@ voss@vmware:~/data/

$(EXECUTABLES): $(OBJECTS)
	$(CC) $(ALLFLAGS) $< --output $@ $(LDFLAGS)


$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)
	rm -f $(OBJECTS)
	rm -f $(HEXFILES)

