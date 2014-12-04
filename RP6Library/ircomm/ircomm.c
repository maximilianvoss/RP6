#include "ircomm.h"

scheduler_t schedIrcommRecv;
scheduler_t schedIrcommSend;

/**
 * Initial function to use IRCOMM service only
 **/
void ircomm(void) {
	/* set interrupt handly for receiving IRCOMM data - none needed. */
	ircommAcs_setInterrupt(NULL);
	
	/* set timer and send function for IRCOMM service only */
	ircommAcs_setTimer(ircomm_timer);
	ircommAcs_setSendFunction(ircomm_send);
	
	/* setup the timer */
	ircommAcs_initTimer();
	
	/* set up task to receiving data */
	schedIrcommRecv.cur_time = 0;
	schedIrcommRecv.exe_time = 1;
	schedIrcommRecv.func = *ircomm_schedulerReceive;
	scheduler_regEvent(&schedIrcommRecv, EVENT_01);
	
	/* set up task to send data */
	schedIrcommSend.cur_time = 0;
	schedIrcommSend.exe_time = 1;
	schedIrcommSend.func = *ircomm_schedulerSend;
	scheduler_regEvent(&schedIrcommSend, EVENT_10);
}
