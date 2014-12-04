#ifndef __ACS_SCHEDULER_H__
#define __ACS_SCHEDULER_H__

#include <core/RP6.h>
#include <ircommAcs/rc5data.h>
#include <ircommAcs/ircommAcs.h>
#include "ircommRecv.h"
#include "ircommSend.h"
#include "acsSend.h"
#include <scheduler/scheduler.h>
#include "states.h"

void acs_scheduler_init(void);
void acs_scheduler(void);
void acs_prepareState(void);

#endif