#ifndef __POWERMGMT_OVERCURRENT_H__
#define __POWERMGMT_OVERCURRENT_H__

#include <core/RP6.h>
#include <scheduler/scheduler.h>
#include "types.h"

void powermgmt_overcurrent(powermgmt_ADCStates_t *ADCStatesIn);
void powermgmt_schedulerOvercurrent(void);

#endif