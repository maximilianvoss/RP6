#ifndef __IRCOMMACS_RC5DATA_H__
#define __IRCOMMACS_RC5DATA_H__

#include <core/RP6.h>

typedef union {
	uint16_t data;
	struct {
		unsigned key_code:6;
		unsigned device:5;
		unsigned toggle_bit:1;
		unsigned reserved:3;
	};
} RC5data_t;

#endif