#ifndef __ENGINE_SCHEDULER_H__
#define __ENGINE_SCHEDULER_H__

#include <engine/hardware.h>

void engine_scheduler();
void inline engine_stop();
void inline engine_setDestEnginePower(uint8_t inDest_pwr_left, uint8_t inDest_pwr_right);

#endif