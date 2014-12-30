#include "powermgmt.h"

static powermgmt_ADCStates_t ADCStates;
static uint8_t current_adc_channel;
scheduler_t schedPowerMgmt;


void powermgmt(void) {
	ADMUX = 0; 
	ADCSRA = (0<<ADIE) | (0<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADIF);
	SFIOR = 0;
	
	current_adc_channel = 0;
	
	schedPowerMgmt.cur_time = 0;
	schedPowerMgmt.exe_time = 1;
	schedPowerMgmt.func = *powermgmt_schedulerPowerMgmt;
	scheduler_regEvent(&schedPowerMgmt, EVENT_1);
	
	powermgmt_overcurrent(&ADCStates);
}


powermgmt_ADCStates_t *powermgmt_getADCStates(void) {
	return &ADCStates;
}

void powermgmt_schedulerPowerMgmt(void) {
	powermgmt_updateADCStates ();
}


void powermgmt_setADCChannel(uint8_t channel) {
	ADMUX = (1<<REFS0) | (0<<REFS1) | (channel<<MUX0);
	ADCSRA = (0<<ADIE) | (1<<ADSC) | (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADIF);
}


void powermgmt_updateADCStates(void) {
	if( !( ADCSRA & (1<<ADSC) ) ) {
		switch(current_adc_channel) {
				case 0: ADCStates.adcBat = ADC; powermgmt_setADCChannel(ADC_MCURRENT_L); break;
				case 1: ADCStates.adcMotorCurrentLeft = ADC; powermgmt_setADCChannel(ADC_MCURRENT_R); break;
				case 2: ADCStates.adcMotorCurrentRight = ADC; powermgmt_setADCChannel(ADC_LS_L); break;
				case 3: ADCStates.adcLSL = ADC; powermgmt_setADCChannel(ADC_LS_R); break;
				case 4: ADCStates.adcLSR = ADC; powermgmt_setADCChannel(ADC_ADC0); break;
				case 5: ADCStates.adc0 = ADC; powermgmt_setADCChannel(ADC_ADC1); break;
				case 6: ADCStates.adc1 = ADC; powermgmt_setADCChannel(ADC_BAT); break;
		}
		current_adc_channel++;
		if ( current_adc_channel > 6 ) {
			current_adc_channel = 0;
		}
	}
}
