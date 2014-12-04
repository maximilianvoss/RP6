#ifndef __IRCOMM_SEND_H__
#define __IRCOMM_SEND_H__

#include <ircommAcs/rc5data.h>
#include <ircommAcs/ircommAcs.h>

void ircomm_schedulerSend(void);
void ircomm_timer(void);
void ircomm_send(RC5data_t *rc5data);

#endif