#ifndef __ENGINE_HARDWARE_H__
#define __ENGINE_HARDWARE_H__

#include <core/RP6.h>

void engine_setHWDist(uint16_t inDist_left, uint16_t inDist_right );
void engine_setHWDistLeft(uint16_t inDist_left);
void engine_setHWDistRight(uint16_t inDist_right);
uint16_t engine_getHWDistLeft(void);
uint16_t engine_getHWDistRight(void);
void engine_setHWDirection(uint8_t dir_left, uint8_t dir_right);
void engine_setHWPower(uint8_t power_left, uint8_t power_right);
void engine_setHWPowerLeft(uint8_t power_right);
void engine_setHWPowerRight(uint8_t power_left);

#endif