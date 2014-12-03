#ifndef __ACS_IRCOMMRECV_H__
#define __ACS_IRCOMMRECV_H__

#include <ircommAcs/rc5data.h>
#include <core/RP6.h>
#include <acs/states.h>

void acs_schedulerReceive();
void acs_setRC5DataHandler( void (*rc5Handler)(RC5data_t *rc5data ));
void acs_interrupt();

#endif