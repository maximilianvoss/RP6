#ifndef __ENGINE_SCHEDULER_H__
#define __ENGINE_SCHEDULER_H__

#include "hardware.h"

void engine_scheduler(void);
void engine_stop(void);
void engine_setDestEnginePower(uint8_t inDest_pwr_left, uint8_t inDest_pwr_right);

#endif