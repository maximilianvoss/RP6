#include <engine/rotation.h>

/**
 * start rotation in a specific angle 
 **/
void engine_rotate(int16_t angle) {
	if ( angle == 0 ) {
		return;
	}
	
	if ( angle > 0 ) {
		engine_setHWDirection (1, 0);
	} else {
		engine_setHWDirection (0, 1);
	}
}