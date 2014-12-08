#include <uart/uart.h>

/**
 * TODO: 
 * - reading from UART
 * - using also HIGH BAUD rates
 */


/** 
 * void uart()
 * initializing UART
 */
void uart(void) {
	UBRRH = UBRR_BAUD_LOW >> 8;
	UBRRL = (uint8_t) UBRR_BAUD_LOW;
	UCSRA = 0x00;
    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
    UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
}

