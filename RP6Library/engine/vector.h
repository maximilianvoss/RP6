#ifndef __ENGINE_VECTOR_H__
#define __ENGINE_VECTOR_H__

#include <core/RP6.h>

typedef struct s_engine_position_vector {
	int16_t x_m;
	int16_t x_mm;
	int16_t y_m;
	int16_t y_mm;
} engine_position_vector_t;

void init_vector(engine_position_vector_t *vec);
engine_position_vector_t diff_vector(engine_position_vector_t *src, engine_position_vector_t *dest);
uint16_t calc_dest_angle(uint16_t inAngle, engine_position_vector_t *src, engine_position_vector_t *dest);

#endif	