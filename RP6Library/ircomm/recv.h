#ifndef __IRCOMM_RECV_H__
#define __IRCOMM_RECV_H__

#include <core/RP6.h>
#include <ircommAcs/rc5data.h>

void ircomm_schedulerReceive(void);
void ircomm_setRC5DataHandler( void (*rc5Handler)(RC5data_t *rc5data ));

#endif