#include "hardware.h"

static uint16_t dist_left;
static uint16_t dist_right;


/* Set distance for left and right */
void engine_setHWDist(uint16_t inDist_left, uint16_t inDist_right ) {
	dist_left = inDist_left;
	dist_right = inDist_right;
}


/* set distance for left */
void engine_setHWDistLeft(uint16_t inDist_left) {
	dist_left = inDist_left;
}


/* set distance for right */
void engine_setHWDistRight(uint16_t inDist_right) {
	dist_right = inDist_right;
}


/* get distance left */
uint16_t engine_getHWDistLeft(void) {
	return dist_left;
}


/* get distance right */
uint16_t engine_getHWDistRight(void) {
	return dist_right;
}


/* set engine directions left and right */
void engine_setHWDirection(uint8_t dir_left, uint8_t dir_right) {
	if(dir_left)
		PORTC |= DIR_L;
	else
		PORTC &= ~DIR_L;
		
	if(dir_right)
		PORTC |= DIR_R;
	else
		PORTC &= ~DIR_R;
}


/* set engine power left and right */
void engine_setHWPower(uint8_t power_left, uint8_t power_right) {
	engine_setHWPowerLeft(power_left);
	engine_setHWPowerRight(power_right);
}


/* set engine power left */
void engine_setHWPowerLeft(uint8_t power_left) {
	if(power_left > 210) {
		power_left = 210;
	}
	OCR1BL = power_left;
}


/* set engine power right */
void engine_setHWPowerRight(uint8_t power_right) {
	if(power_right > 210) {
		power_right = 210;	
	}
	OCR1AL = power_right;
}


/* encoder left */
ISR (INT0_vect) {
	dist_left++;
}


/* encoder right */
ISR (INT1_vect) {
	dist_right++;
}
