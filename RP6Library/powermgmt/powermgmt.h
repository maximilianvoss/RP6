#ifndef __POWERMGMT_POWERMGMT_H__
#define __POWERMGMT_POWERMGMT_H__

#include <core/RP6.h>
#include <scheduler/scheduler.h>
#include "overcurrent.h"
#include "types.h"

void powermgmt(void);
powermgmt_ADCStates_t *powermgmt_getADCStates(void);
void powermgmt_schedulerPowerMgmt(void);
void powermgmt_setADCChannel(uint8_t channel);
void powermgmt_updateADCStates(void);

#endif