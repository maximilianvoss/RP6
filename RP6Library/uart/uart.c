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
void uart() {
	UBRRH = UBRR_BAUD_LOW >> 8;
	UBRRL = (uint8_t) UBRR_BAUD_LOW;
	UCSRA = 0x00;
    UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
    UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
}


/**
 * void writeChar(char ch)
 * writing a single char to UART
 * @IN: char ch: the char to write
 */
void uart_writeChar(char ch) {
    while (!(UCSRA & (1<<UDRE)));
    UDR = (uint8_t)ch;
}


/**
 * void writeString(char *str)
 * writing a \0 terminated string to UART
 * @IN: char *str: the string to send
 */
void uart_writeString(char *str) {
	while(*str)
		uart_writeChar(*str++);
}


/**
 * void writeNStringP(const char *pstring)
 * writing a static string which is contained in the program source. Decreases memory usage
 * @IN const char *pstring: pointer on the program code
 */
void uart_writeNStringP(const char *pstring) {
    uint8_t c;
    for (;(c = pgm_read_byte_near(pstring++)); uart_writeChar(c));
}


/**
 * void writeStringLength(char *str, uint8_t len, uint8_t offset)
 * writing a specific lenght of a string. Starting at offset
 * @IN: char *str: the string
 * @IN: uint8_t len: lenght to write
 * @IN: uint8_t offset: the offset where to start the string
 */
void uart_writeStringLength(char *str, uint8_t len, uint8_t offset) {
	for(str = &str[offset]; *str && len; len--)
		uart_writeChar(*str++);
}


/**
 * void writeInteger(int16_t number, uint8_t base)
 * writing an integer to UART. Converting the number into the right base 
 * @IN: int16_t number: an integer
 * @IN: uint8_t base: the base to display (10=dec, 2=bin, 16=hex)
 */
void uart_writeInteger(int16_t number, uint8_t base) {
	char buffer[17];
	itoa(number, &buffer[0], base);
	uart_writeString(&buffer[0]);
}


/** 
 * void writeIntegerLength(int16_t number, uint8_t base, uint8_t len)
 * writing an integer to UART. It's extended to lenght len or truncated to it. Base is same as writeInteger
 * @IN: int16_t number: the number to send
 * @IN: uint8_t base: the base to display (10=dec, 2=bin, 16=hex)
 * @IN: uint8_t len: the length in which the number should be displayed
 */
void uart_writeIntegerLength(int16_t number, uint8_t base, uint8_t len) {
	char buffer[17];
	itoa(number, &buffer[0], base);
	int8_t cnt = len - strlen(buffer);
	if(cnt > 0) {
		for(; cnt > 0; cnt--, uart_writeChar('0'));
		uart_writeString(&buffer[0]);
	}
	else 
		uart_writeStringLength(&buffer[0],len,-cnt);
}
