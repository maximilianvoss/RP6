#ifndef __UART_UARTREAD_H__
#define __UART_UARTREAD_H__

#include <core/RP6.h>

// RX:
extern volatile uint8_t uart_status;

#define UART_RECEIVE_BUFFER_SIZE 32 // Default buffer size is 32!
#define UART_BUFFER_OK 0
#define UART_BUFFER_OVERFLOW 1

char readChar(void);
uint8_t readChars(char *buf, uint8_t numberOfChars);
uint8_t getBufferLength(void);
void clearReceptionBuffer(void);

#endif