#include <core/bumper.h>

/**
 * uint8_t inline isBumperLeft()
 * is a inline function to get the state of the left bumper.
 * @OUT: left bumper state
 */
uint8_t isBumperLeft(void) {
	return PINB & SL6;
}


/**
 * uint8_t inline isBumperRight()
 * is a inline function to get the state of the right bumper.
 * @OUT: right bumper state
 */
uint8_t isBumperRight(void) {
	return PINC & SL3;
}
