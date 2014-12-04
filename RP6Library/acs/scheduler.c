#include "scheduler.h"
#include <scheduler/scheduler.h>

scheduler_t schedAcsRecv;
scheduler_t schedAcsSend;

void acs_scheduler_init(void) {
	/* set interrupt handly for receiving IRCOMM data - none needed. */
	ircommAcs_setInterrupt(acs_interrupt);
	
	/* set timer and send function for IRCOMM service only */
	ircommAcs_setTimer(acs_ircomm_timer);

	/* setup the timer */
	ircommAcs_initTimer();
	
	acs_state = IRCOMM_SEND;
	
	/* set up task to receiving data */
	schedAcsRecv.cur_time = 0;
	schedAcsRecv.exe_time = 1;
	schedAcsRecv.func = *acs_schedulerReceive;
	scheduler_regEvent(&schedAcsRecv, EVENT_01);
	
	/* set up task to send data */
	schedAcsSend.cur_time = 0;
	schedAcsSend.exe_time = 1;
	schedAcsSend.func = NULL;
	scheduler_regEvent(&schedAcsSend, EVENT_10);	
}


void acs_scheduler(void) {
	acs_prepareState();
}


void acs_prepareState(void) {
	switch ( acs_state ) {
		case IRCOMM_IDLE:
		break;
		case IRCOMM_SEND:
			ircommAcs_setSendFunction(acs_ircomm_send);
			schedAcsSend.func = *acs_ircomm_schedulerSend;
		break;
		case ACS_STATE_SEND_LEFT:
		break;
		case ACS_STATE_WAIT_LEFT:
		break;
		case ACS_STATE_SEND_RIGHT:
		break;
		case ACS_STATE_WAIT_RIGHT:
		break;
	}
}
