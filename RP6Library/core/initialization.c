#include <core/initialization.h>
#include <core/RP6.h>
#include <core/buttons.h>

void init() {
	cli();
	
	portInit();
	
	IRCOMM_OFF();
	
	/* power on */
	PORTB |= PWRON;
	enableResetButton();
	
		// Initialize ADC:
	ADMUX = 0; //external reference 
	ADCSRA = (0<<ADIE) | (0<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADIF);
	SFIOR = 0;

	// Initialize External interrupts:
	MCUCR = (0 << ISC11) | (1 << ISC10) | (0 << ISC01) | (1 << ISC00);
	GICR = (1 << INT2) | (1 << INT1) | (1 << INT0);
	MCUCSR = (0 << ISC2);
	
	/* Init timer interrupts */
	TIMSK = (1 << OCIE0); 
	sei();
}


/**
 * void initTimers()
 * initializing all timer functionalities for stopwatches, delays and whatever 
 */
void initTimers() {
	/* Initialize Timer1 - PWM: PWM, phase correct with ICR1 as top value. */
	TCCR1A = (0 << WGM10) | (1 << WGM11) | (1 << COM1A1) | (1 << COM1B1);
	TCCR1B =  (1 << WGM13) | (0 << WGM12) | (1 << CS10);
	OCR1AL = 0;
	OCR1BL = 0;
	ICR1 = 210; 
	/* Phase corret PWM top value - 210 results in about 19 kHz PWM.
		ICR1 is the maximum (=100% duty cycle) PWM value! This means that 
		the PWM resolution is a bit lower, but if the frequency is lower 
		than 19 kHz you may hear very annoying high pitch noises from the motors!
		19 kHz is a bit over the maximum frequency most people can hear!
		
		 ATTENTION: Max PWM value is 210 and NOT 255 !!!*/

	/* init Timer2 for ACS */
	#ifdef COMPILE_ENABLE_IRCOMM
		TCCR2 = (1 << WGM21) | (0 << COM20) | (1 << CS20);
		/* 0x6E = 72kHz @8MHz */
		OCR2  = 0x6E; 
	#endif
}