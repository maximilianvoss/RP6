//
//  uartread.c
//  RP6Library
//
//  Created by Maximilian Voss on 08/12/14.
//  Copyright (c) 2014 Maximilian Voss. All rights reserved.
//

#include "uartread.h"


// UART receive functions:

// MAXIMUM Buffer size is 254.
volatile char uart_receive_buffer[UART_RECEIVE_BUFFER_SIZE+1];

volatile uint8_t uart_status;

uint8_t read_pos = 0;
uint8_t write_pos = 0;
uint8_t read_size = 0;
uint8_t write_size = 0;

/**
 * UART receive ISR.
 * Handles reception to circular buffer.
 */
ISR(USART_RXC_vect)
{
    static volatile uint8_t dummy;
    if(((uint8_t)(write_size - read_size)) < UART_RECEIVE_BUFFER_SIZE) {
        uart_receive_buffer[write_pos++] = UDR;
        write_size++;
        if(write_pos > UART_RECEIVE_BUFFER_SIZE)
            write_pos = 0;
        uart_status = UART_BUFFER_OK;
    }
    else {
        dummy = UDR;
        uart_status = UART_BUFFER_OVERFLOW;
    }
}

/**
 * Read a char from the circular buffer.
 * The char is removed from the buffer (or more precise: not accessible directly anymore
 * and will be overwritten as soon as new data becomes available)!
 *
 * Example:
 *
 * // [...]
 * if(getBufferLength())
 *	   receivedData[data_position++] = readChar();
 * // [...]
 *
 */
char uart_readChar(void)
{
    uart_status = UART_BUFFER_OK;
    if(((uint8_t)(write_size - read_size)) > 0) {
        read_size++;
        if(read_pos > UART_RECEIVE_BUFFER_SIZE)
            read_pos = 0;
        return uart_receive_buffer[read_pos++];
    }
    return 0;
}

/**
 * Same as readChar, but this function copies numberOfChars chars from the
 * circular buffer to buf.
 * It also returns the number of characters really copied to the buffer!
 * Just in case that there were fewer chars in the buffer...
 */
uint8_t uart_readChars(char *buf, uint8_t numberOfChars)
{
    uint8_t i = 0;
    uart_status = UART_BUFFER_OK;
    while(((uint8_t)(write_size - read_size))  > 0 && i < numberOfChars) {
        read_size++;
        buf[i++] = uart_receive_buffer[read_pos++];
        if(read_pos > UART_RECEIVE_BUFFER_SIZE)
            read_pos = 0;
    }
    return i;
}

/**
 * Returns the current number of elements in the buffer.
 *
 * Example:
 * s. readChar function above!
 */
uint8_t uart_getBufferLength(void)
{
    return (((uint8_t)(write_size - read_size)));
}

/**
 * Clears the reception buffer - it disables UART Receive
 * interrupt for a short period of time.
 */
void uart_clearReceptionBuffer(void)
{
    static uint8_t dummy;
    UCSRB &= ~(1 << RXCIE); // disable UART RX Interrupt
    dummy = UDR;
    read_pos = 0;
    write_pos = 0;
    read_size = 0;
    write_size = 0;
    uart_status = UART_BUFFER_OK;
    UCSRB |= (1 << RXCIE); // enable Interrupt again
}