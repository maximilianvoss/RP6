#include "acs.h"

scheduler_t schedAcsSched;

void acs(void) {
	acs_scheduler_init();
	
	/* set up task to send data */
	schedAcsSched.cur_time = 0;
	schedAcsSched.exe_time = 1;
	schedAcsSched.func = NULL;
	scheduler_regEvent(&schedAcsSched, EVENT_10);	
}