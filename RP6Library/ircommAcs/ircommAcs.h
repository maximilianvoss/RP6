#ifndef __IRCOMMACS_IRCOMMACS_H__
#define __IRCOMMACS_IRCOMMACS_H__

#include <ircommAcs/rc5data.h>

void ircommAcs_setTimer( void (*handler)() );
void ircommAcs_setInterrupt( void (*handler)() );
void ircommAcs_setSendFunction( void (*handler)(RC5data_t *rc5data) );

void inline ircommAcs_sendData(RC5data_t *rc5data);
void inline ircommAcs_initTimer();
void inline ircommAcs_startTimer();
void inline ircommAcs_stopTimer();

#endif