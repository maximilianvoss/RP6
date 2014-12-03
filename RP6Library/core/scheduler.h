#ifndef __ACS_SCHEDULER_H__
#define __ACS_SCHEDULER_H__

#include <core/RP6.h>
#include <ircommAcs/rc5data.h>
#include <ircommAcs/ircommAcs.h>
#include <acs/ircommRecv.h>
#include <acs/ircommSend.h>
#include <acs/acsSend.h>
#include <scheduler/scheduler.h>
#include <acs/states.h>

void acs_scheduler_init();
void acs_scheduler();
void inline acs_prepareState();

#endif