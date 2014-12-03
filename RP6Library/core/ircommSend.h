#ifndef __ACS_IRCOMMSEND_H__
#define __ACS_IRCOMMSEND_H__

#include <ircommAcs/rc5data.h>
#include <ircommAcs/ircommAcs.h>

void acs_ircomm_schedulerSend();
void acs_ircomm_timer();
void acs_ircomm_send(RC5data_t *rc5data);

#endif