#ifndef __CORE_INITIALIZATION_H__
#define __CORE_INITIALIZATION_H__

#include "RP6.h"

#define portInit();	\
PORTA = INIT_PRTA;	\
PORTB = INIT_PRTB;	\
PORTC = INIT_PRTC;	\
PORTD = INIT_PRTD;	\
DDRA = INIT_DDRA;	\
DDRB = INIT_DDRB;	\
DDRC = INIT_DDRC;	\
DDRD = INIT_DDRD;

void init(void);
void initTimers(void);

#endif