#ifndef __SCHEDULER_SCHEDULER_H__
#define __SCHEDULER_SCHEDULER_H__

#include <avr/io.h>	
#include <avr/interrupt.h>
#include <stdlib.h>
#include "sleep.h"

/* chain definitions */
#define EVENT_01 0 		/* 0.1 microseconds */
#define EVENT_1 1		/* 1 microseconds */
#define EVENT_10 2		/* 10 microseconds */
#define EVENT_100 3		/* 100 microseconds */
#define EVENT_1000 4	/* seconds */

/* timerevent structure */
typedef struct scheduler_s {
	volatile uint16_t cur_time; 			/* current counter, counts from 0 to exe_time */
	uint16_t exe_time;			/* when to execute the function, maximum value of cur_time */
	void (*func) (void);			/* the function which has to be executed after exe_time has been reached */
	struct scheduler_s *next;  /* a pointer to the next timerevent structure */
} scheduler_t;

/* a counter from 0 to 1000 */
static uint16_t volatile timer;

void scheduler(void);
void scheduler_regEvent(scheduler_t *inEvent, uint8_t type);
void scheduler_unregEvent(scheduler_t *inEvent, uint8_t type);
void scheduler_execEvents(scheduler_t *inEvent);
#endif