#include "engine.h"
#include <scheduler/scheduler.h>
#include <powermgmt/powermgmt.h>

static engine_position_vector_t cur_vec_left;
static engine_position_vector_t cur_vec_right;
static engine_position_vector_t dest_vec_left;
static engine_position_vector_t dest_vec_right;
static uint16_t cur_angle;
static uint16_t dest_angle;

void engine(void) {
    powermgmt();
	engine_setHWDist(0,0);
	engine_scheduler();
	
	cur_angle = 0;
	dest_angle = 0;
	
	init_vector(&cur_vec_left);
	init_vector(&cur_vec_right);
	init_vector(&dest_vec_left);
	init_vector(&dest_vec_right);
}


void updatePosition(void) {
	if ( cur_angle != dest_angle ) {
	}
}
