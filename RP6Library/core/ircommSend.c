#include <acs/ircommSend.h>

static volatile uint8_t ircomm_transmission;
static volatile uint16_t ircomm_data_to_send;


/** 
 * task to send IRCOMM data only
 **/
void acs_ircomm_schedulerSend() {
	if (ircomm_transmission) {
		ircommAcs_startTimer();
	} else {
		ircommAcs_stopTimer();
	}
}


/**
 * function to initiate IRCOMM transmission 
 **/
void acs_ircomm_send(RC5data_t *rc5data) {
	ircomm_data_to_send = 0x3000 | rc5data->data;
	ircomm_transmission = 14;
}


/**
 * interrupt timer function to do the actual IRCOMM transmission
 **/
void acs_ircomm_timer() {
	static uint8_t ircomm_pulse;
	
	if ( ircomm_pulse ) {
		/* there is data to send */
		if ( ircomm_pulse < 60 ) {
			if ( ircomm_data_to_send & 0x4000 ) {
				IRCOMM_ON();
			} else {
				IRCOMM_OFF();
			}
		} else {
			if ( ircomm_data_to_send & 0x4000 ) {
				IRCOMM_OFF();
			} else {
				IRCOMM_ON();
			}
		}
		ircomm_pulse--;		
	} else {
		if ( ircomm_transmission ) {
			/* still something to transmit */
			IRCOMM_OFF();
			ircomm_data_to_send <<= 1; 
			ircomm_pulse = 120;
			ircomm_transmission--;
		} else {
			IRCOMM_OFF();
		}
	}
}
