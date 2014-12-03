#ifndef __ENGINE_HARDWARE_H__
#define __ENGINE_HARDWARE_H__

#include <core/RP6.h>

void inline engine_setHWDist(uint16_t inDist_left, uint16_t inDist_right );
void inline engine_setHWDistLeft(uint16_t inDist_left);
void inline engine_setHWDistRight(uint16_t inDist_right);
uint16_t inline engine_getHWDistLeft();
uint16_t inline engine_getHWDistRight();
void inline engine_setHWDirection(uint8_t dir_left, uint8_t dir_right);
void inline engine_setHWPower(uint8_t power_left, uint8_t power_right);
void inline engine_setHWPowerLeft(uint8_t power_right);
void inline engine_setHWPowerRight(uint8_t power_left);

#endif