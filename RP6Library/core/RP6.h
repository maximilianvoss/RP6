#ifndef __CORE_RP6_H__
#define __COER_RP6_H__

#include <avr/io.h>	
#include <avr/interrupt.h>
#include <stdlib.h>

/* Port A */
#define UBAT 			(1 << PINA7) // ADC7 (Input)
#define MCURRENT_L 		(1 << PINA6) // ADC6 (Input)
#define MCURRENT_R 		(1 << PINA5) // ADC5 (Input)
#define E_INT1 			(1 << PINA4) // INT1 (input per default... can be output)
#define LS_L 			(1 << PINA3) // ADC3 (Input)
#define LS_R 			(1 << PINA2) // ADC2 (Input)
#define ADC1 			(1 << PINA1) // ADC1 (Input)
#define ADC0 			(1 << PINA0) // ADC0 (Input)

/* PortA A/D Convertor channels */
#define ADC_BAT 			7
#define ADC_MCURRENT_L 		6
#define ADC_MCURRENT_R 		5
#define ADC_LS_L 			3
#define ADC_LS_R 			2
#define ADC_ADC1 			1
#define ADC_ADC0 			0

/* Port B */
#define SL4 		(1 << PINB7)	// Output
#define ACS_L 		(1 << PINB6)	// Output
#define START 		(1 << PINB5)	// Input
#define PWRON		(1 << PINB4)	// Output
#define ACS_PWRH	(1 << PINB3)	// Output
#define ACS 		(1 << PINB2)	// INT2 (Input)
#define SL5 		(1 << PINB1)	// Output
#define SL6 		(1 << PINB0)	// Output

/* Port C */
#define ACS_R 		(1 << PINC7)	// Output
#define SL3 		(1 << PINC6)	// Output
#define SL2 		(1 << PINC5)	// Output
#define SL1 		(1 << PINC4)	// Output
#define DIR_R 		(1 << PINC3)	// Output
#define DIR_L 		(1 << PINC2)	// Output
#define SDA 		(1 << PINC1)	// I2C Data (I/O)
#define SCL 		(1 << PINC0)	// I2C Clock (Output (Master), Input (Slave))

/* Port D */
#define ACS_PWR	(1 << PIND6)	// Output
#define MOTOR_R	(1 << PIND5)	// PWM Output (OC1A)
#define MOTOR_L	(1 << PIND4)	// PWM Output (OC1B)
#define ENC_R 	(1 << PIND3)	// INT1 (Input)
#define ENC_L 	(1 << PIND2)	// INT0 (Input)
#define TX 		(1 << PIND1)	// USART TX (Output)
#define RX 		(1 << PIND0)	// USART RX (Input)


/* Initial value of port and direction registers */
/* Port A */
#define INIT_DDRA 0b00000000
#define INIT_PRTA 0b00000000

/* Port B */
#define INIT_DDRB 0b01011000
#define INIT_PRTB 0b00000000

/* Port C */
#define INIT_DDRC 0b10001100
#define INIT_PRTC 0b00000000

/* Port D */
#define INIT_DDRD 0b11110010
#define INIT_PRTD 0b00000001

/* IRCOMM OFF */
#define IRCOMM_OFF() PORTD &= ~(1 << PIND7);
/* IRCOMM ON */
#define IRCOMM_ON() PORTD ^= (1<<PIND7); 


/* setting CPU speed */
#ifdef F_CPU
	#undef F_CPU
#endif
#ifndef F_CPU
	#define F_CPU 8000000
#endif

#endif