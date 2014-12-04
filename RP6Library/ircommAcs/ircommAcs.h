#ifndef __IRCOMMACS_IRCOMMACS_H__
#define __IRCOMMACS_IRCOMMACS_H__

#include "rc5data.h"

void ircommAcs_setTimer( void (*handler)(void) );
void ircommAcs_setInterrupt( void (*handler)(void) );
void ircommAcs_setSendFunction( void (*handler)(RC5data_t *rc5data) );

void ircommAcs_sendData(RC5data_t *rc5data);
void ircommAcs_initTimer(void);
void ircommAcs_startTimer(void);
void ircommAcs_stopTimer(void);

#endif