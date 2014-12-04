/** 
 * This file exists because of it might be possible to use IRCOMM without ACS support vise versa. 
 * So it's important to build up a system that at least supports IRCOMM without ACS and ACS with IRCOMM
 **/

#include "ircommAcs.h"

static void (*ircommAcs_handlerTimer)(void) = NULL;
static void (*ircommAcs_handlerInterrupt)(void) = NULL;
static void (*ircommAcs_handlerSendFunction)(RC5data_t *rc5data) = NULL;


/**
 * This function is to configure the timer interrupt correctly on 72kHz modulation for IRCOMM/ACS
 **/
void ircommAcs_initTimer(void) {
	ircommAcs_stopTimer();
	TCCR2 = (1 << WGM21) | (0 << COM20) | (1 << CS20);
	/* 0x6E = 72kHz @8MHz */
	OCR2  = 0x6E; 
}


/**
 * enable the interrupt timer for IRCOMM/ACS 
 **/
void ircommAcs_startTimer(void) {
	TIMSK |= (1 << OCIE2);
}


/**
 * disable the interrupt timer for IRCOMM/ACS
 **/
void ircommAcs_stopTimer(void) {
	TIMSK &= ~(1 << OCIE2);
}


/**
 * Wrapper function for sending RC5 data
 * Useful if you use IRCOMM without ACS or an ACS handler doing the IRCOMM sending
 **/
void ircommAcs_sendData(RC5data_t *rc5data) {
	if ( ircommAcs_handlerSendFunction != NULL ) {
		ircommAcs_handlerSendFunction(rc5data);
	}
}


/**
 * Sets up the IRCOMM/ACS send function
 * It's the function ircommSend calls to send the rc5data package
 **/
void ircommAcs_setSendFunction( void (*handler)(RC5data_t *rc5data) ) {
	ircommAcs_handlerSendFunction = handler;
}


/**
 * Sets up the IRCOMM/ACS timer function. 
 * The handler is the function doing the actual sending of IRCOMM/ACS data
 **/
void ircommAcs_setTimer( void (*handler)(void) ) {
	ircommAcs_handlerTimer = handler;
}


/**
 * Seting the IRCOMM/ACS interrupt
 **/
void ircommAcs_setInterrupt( void (*handler)(void) ) {
	ircommAcs_handlerInterrupt = handler;
}


/**
 * Interrupt for IRCOMM/ACS 
 **/
ISR (TIMER2_COMP_vect) {
	if ( ircommAcs_handlerTimer != NULL ) {
		ircommAcs_handlerTimer();
	}
}


/**
 * Interrupt receiving IRCOMM/ACS package 
 **/
ISR (INT2_vect) {
	if ( ircommAcs_handlerInterrupt != NULL ) {
		ircommAcs_handlerInterrupt();
	}
}