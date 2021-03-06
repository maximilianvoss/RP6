#include "overcurrent.h"

scheduler_t schedOvercurrent;
static powermgmt_ADCStates_t *ADCStates;

void powermgmt_overcurrent(powermgmt_ADCStates_t *ADCStatesIn) {
	schedOvercurrent.cur_time = 0;
	schedOvercurrent.exe_time = 1;
	schedOvercurrent.func = *powermgmt_schedulerOvercurrent;
	scheduler_regEvent(&schedOvercurrent, EVENT_10);
	
    ADCStates = ADCStatesIn;
}


/**
 * task to identify overcurrents in the engine 
 **/
void powermgmt_schedulerOvercurrent(void) {
	if ( ADCStates->adcMotorCurrentLeft > 770 || ADCStates->adcMotorCurrentRight > 770 ) {
		cli();
		OCR1AL = 0;
		OCR1BL = 0;
		TCCR1A = 0;
		PORTB &= ~PWRON;
		while(1);
	}
}
