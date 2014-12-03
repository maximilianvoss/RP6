#ifndef __ACS_STATES_H__
#define __ACS_STATES_H__

#include <core/RP6.h>

#define IRCOMM_IDLE 0
#define IRCOMM_SEND 1
#define ACS_STATE_SEND_LEFT 2
#define ACS_STATE_WAIT_LEFT 3
#define ACS_STATE_SEND_RIGHT 4
#define ACS_STATE_WAIT_RIGHT 5

static uint8_t volatile acs_state;

#endif