#include <engine/vector.h>
#include <math.h>

void inline init_vector(engine_position_vector_t *vec) {
	vec->x_m = 0;
	vec->x_mm = 0;
	vec->y_m = 0;
	vec->y_mm = 0;
}


engine_position_vector_t diff_vector(engine_position_vector_t *src, engine_position_vector_t *dest) {
	engine_position_vector_t vec;
	vec.x_m = dest->x_m - src->x_m;
	vec.x_mm = dest->x_mm - src->x_mm;
	
	if ( vec.x_mm > 1000 ) {
		vec.x_m++;
		vec.x_mm -= 1000;
	} else if ( vec.x_mm < -1000 ) {
		vec.x_m--;
		vec.x_mm += 1000;
	}
	if ( vec.x_m > 0 && vec.x_mm < 0 ) {
		vec.x_m--;
		vec.x_mm = 1000 + vec.x_mm;
	} else if ( vec.x_m < 0 && vec.x_mm > 0 ) {
		vec.x_m++;
		vec.x_mm = 1000 - vec.x_mm;
	}

	vec.y_m = dest->y_m - src->y_m;
	vec.y_mm = dest->y_mm - src->y_mm;

	if ( vec.y_mm > 1000 ) {
		vec.y_m++;
		vec.y_mm -= 1000;
	} else if ( vec.y_mm < -1000 ) {
		vec.y_m--;
		vec.y_mm += 1000;
	}
	if ( vec.y_m > 0 && vec.y_mm < 0 ) {
		vec.y_m--;
		vec.y_mm = 1000 + vec.y_mm;
	} else if ( vec.y_m < 0 && vec.y_mm > 0 ) {
		vec.y_m++;
		vec.y_mm = 1000 - vec.y_mm;
	}
	
	return vec;
}


uint16_t calc_dest_angle(uint16_t inAngle, engine_position_vector_t *src, engine_position_vector_t *dest) {
	float x;
	float y;
	float angle;
	
	x = (dest->x_m + dest->x_mm) - (src->x_m + src->x_mm);
	y = (dest->y_m + dest->y_mm) - (src->y_m + src->y_mm);
	
	angle = atan2(y, x);
	
	return 0;
}
