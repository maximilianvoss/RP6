#ifndef __UART_UART_H__
#define __UART_UART_H__

#include "uartread.h"
#include "uartwrite.h"

#define HEX 16
#define DEC 10
#define OCT 8
#define BIN 2

/* Baudrates */
#define BAUD_LOW		38400  //Low speed - 38.4 kBaud
#define UBRR_BAUD_LOW	((F_CPU/(16*BAUD_LOW))-1)

#define BAUD_HIGH		500000 //High speed - 500 kBaud
#define UBRR_BAUD_HIGH	((F_CPU/(16*BAUD_HIGH))-1)

#endif