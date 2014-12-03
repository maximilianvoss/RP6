#ifndef __POWERMGMT_POWERMGMT_H__
#define __POWERMGMT_POWERMGMT_H__

#include <core/RP6.h>
#include <scheduler/scheduler.h>
#include <powermgmt/overcurrent.h>

/* ADC states */
typedef struct ADCStates_s {
	uint16_t adcBat;
	uint16_t adcMotorCurrentLeft;
	uint16_t adcMotorCurrentRight;
	uint16_t adcLSL;
	uint16_t adcLSR;
	uint16_t adc0;
	uint16_t adc1;
} powermgmt_ADCStates_t;

void powermgmt();
powermgmt_ADCStates_t *powermgmt_getADCStates();
void inline powermgmt_schedulerPowerMgmt();
void inline powermgmt_setADCChannel(uint8_t channel);
void powermgmt_updateADCStates();

#endif