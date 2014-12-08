#ifndef __UART_UARTWRITE_H__
#define __UART_UARTWRITE_H__

#include <core/RP6.h>
#include <string.h>
#include <avr/pgmspace.h>

/* macro for writing a string which is a constant in the source code */
#define uart_writeString_P(__pstr) uart_writeNStringP((PSTR(__pstr)))

void uart(void);
void uart_writeChar(char ch);
void uart_writeString(char *str);
void uart_writeNStringP(const char *pstr);
void uart_writeStringLength(char *str, uint8_t len, uint8_t offset);
void uart_writeInteger(int16_t number, uint8_t base);
void uart_writeIntegerLength(int16_t number, uint8_t base, uint8_t len);

#endif
