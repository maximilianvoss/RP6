#include <core/leds.h>


static LEDs_t statusLEDs;

/**
 * void initLEDs()
 * sets all LEDs to off
 */
void leds(void) {
	setLEDs(0);
}


/**
 * void updateStatusLEDs()
 * the LEDs are switched according to the struct statusLEDs
 */
void updateLEDs(void) {
	DDRB &= ~0x83;
	PORTB &= ~0x83;
	if(statusLEDs.LED4){ DDRB |= SL4; PORTB |= SL4; }
	if(statusLEDs.LED5){ DDRB |= SL5; PORTB |= SL5; }
	if(statusLEDs.LED6){ DDRB |= SL6; PORTB |= SL6; }
	DDRC &= ~0x70;
	PORTC &= ~0x70;
	DDRC |= ((statusLEDs.byte << 4) & 0x70);
	PORTC |= ((statusLEDs.byte << 4) & 0x70);
}


LEDs_t* getStatusLEDs(void) {
    return &statusLEDs;
}


/**
 * void inline setLEDs(uint8_t leds) 
 * a setting the LEDs state 
 * @IN: uint8_t leds: how the LEDs should be switched, have a look at t_LEDs
 */
void setLEDs(uint8_t leds) {
	statusLEDs.byte = leds;
	updateLEDs();
}

void ledPowerOn(void){
    PORTB |= PWRON;
}

void ledPowerOff(void){
    PORTB &= ~PWRON;
}
