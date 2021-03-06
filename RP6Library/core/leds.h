#ifndef __CORE_LEDS_H__
#define __CORE_LEDS_H__

#include "RP6.h"

/* LEDs */
typedef union {
 	uint8_t byte;
	struct {
		unsigned LEDsR:3;
		unsigned LEDsL:3;
		unsigned reserved:2;
	};
	struct {
		unsigned LED1:1;
		unsigned LED2:1;
		unsigned LED3:1;
		unsigned LED4:1;
		unsigned LED5:1;
		unsigned LED6:1;
		unsigned reserved1:1;
		unsigned reserved2:1;
	};
} LEDs_t;

void leds(void);
void updateLEDs(void);
void setLEDs(uint8_t leds);
void ledPowerOn(void);
void ledPowerOff(void);
LEDs_t* getStatusLEDs(void);

#endif