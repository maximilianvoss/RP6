#include <engine/scheduler.h>
#include <scheduler/scheduler.h>

scheduler_t schedEngineSched;
uint8_t dest_pwr_left;
uint8_t dest_pwr_right;
uint8_t curr_pwr_left;
uint8_t curr_pwr_right;

void engine_scheduler() {
	curr_pwr_left = 0;
	curr_pwr_right = 0;
	dest_pwr_left = 0;
	dest_pwr_right = 0;
	
	schedEngineSched.cur_time = 0;
	schedEngineSched.exe_time = 2;
	schedEngineSched.func = NULL;
	scheduler_regEvent(&schedEngineSched, EVENT_100);	
}


void inline engine_stop() {
	engine_setHWPower(0,0);
	curr_pwr_left = 0;
	curr_pwr_right = 0;
	dest_pwr_left = 0;
	dest_pwr_right = 0;
}


void inline engine_setDestEnginePower(uint8_t inDest_pwr_left, uint8_t inDest_pwr_right) {
	dest_pwr_left = inDest_pwr_left;
	dest_pwr_right = inDest_pwr_right;
}
