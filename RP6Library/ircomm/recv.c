#include "recv.h"
#include<uart/uart.h>

#define RC5_TIME 		1.778e-3
#define RC5_PULSE_MIN	(uint8_t)(10e3 * RC5_TIME * 0.4 + 0.5)
#define RC5_PULSE_1_2	(uint8_t)(10e3 * RC5_TIME * 0.8 + 0.5)
#define RC5_PULSE_MAX	(uint8_t)(10e3 * RC5_TIME * 1.2 + 0.5)

static void (*ircomm_RC5DataHandler)(RC5data_t *rc5data);
static uint8_t rc5_data_received;


/**
 * Task to receive IRCOMM transmissions
 **/
void ircomm_schedulerReceive(void) {
	static uint8_t IRCOMM_RC5_bit;
	static uint8_t IRCOMM_RC5_time;
	static uint16_t IRCOMM_RC5_tmp;
	RC5data_t data;
	uint16_t tmp;
	
	if ( ( !rc5_data_received ) ) {
        uart_writeString_P("Huhu");

		tmp = IRCOMM_RC5_tmp;
		
		if ( ++IRCOMM_RC5_time > RC5_PULSE_MAX ) {
			if ( !( tmp & 0x4000 ) && ( tmp & 0x2000 ) ) {
				data.data = tmp;
				rc5_data_received = 1;
			}
			tmp = 0;
		}
		
		if ( ( IRCOMM_RC5_bit ^ PINB ) & ACS ) {
			IRCOMM_RC5_bit = ~IRCOMM_RC5_bit;
			
			if ( IRCOMM_RC5_time < RC5_PULSE_MIN ) {
				tmp = 0;
			}
			
			if ( !tmp || ( IRCOMM_RC5_time > RC5_PULSE_1_2 ) ) {
				if ( !( tmp & 0x4000 ) ) {
					tmp <<= 1;
				}
				if ( !( IRCOMM_RC5_bit & ACS ) ) {
					tmp |= 1;
				}
				IRCOMM_RC5_time = 0;
			}
		}
		IRCOMM_RC5_tmp = tmp;	
	}
	if ( rc5_data_received ) {
        uart_writeString_P("RC5 Data");

		if (ircomm_RC5DataHandler != NULL ) {
			ircomm_RC5DataHandler(&data);
		}
		data.data = 0;
		rc5_data_received = 0;
	}
}


/**
 * Setting up the data handler which has to be called when data received 
 **/
void ircomm_setRC5DataHandler( void (*rc5Handler)(RC5data_t *rc5data) ) {
	ircomm_RC5DataHandler = rc5Handler;
}
