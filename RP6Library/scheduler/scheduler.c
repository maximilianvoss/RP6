#include "scheduler.h"

/* declaration */
scheduler_t *events01 = NULL;
scheduler_t *events1 = NULL;
scheduler_t *events10 = NULL;
scheduler_t *events100 = NULL;
scheduler_t *events1000 = NULL;


/**
 * void scheduler()
 * initializing all timer functionalities for stopwatches, delays and whatever 
 */
void scheduler(void) {
	timer = 0;
	
	/* Initialize Timer 0 -  100µs cycle for Delays/Stopwatches, RC5 reception etc.: */
	TCCR0 =   (0 << WGM00) | (1 << WGM01) 
			| (0 << COM00) | (0 << COM01) 
			| (0 << CS02)  | (1 << CS01) | (0 << CS00);
	OCR0  = 99;
    
    sleepInit();
}


/**
 * Timer interrupt in 0.1ms resolution. The right chain is going to be executed after the specific time has passed
 */
ISR (TIMER0_COMP_vect) {
	timer++;

	scheduler_execEvents(events01);
	/* microseconds */
	if ( timer % 10 == 0 ) {
		scheduler_execEvents(events1);
		/* 10 microseconds */
		if ( timer % 100 == 0 ) {
			scheduler_execEvents(events10);
			/* 100 microseconds */
			if ( timer % 1000 == 0 ) {
				scheduler_execEvents(events100);
				/* seconds */
				if ( timer % 10000 == 0 ) {
					scheduler_execEvents(events1000);
					timer = 0;
				}			
			}
		}
	}
}


/**
 * void regEvent(scheduler_t *inEvent, uint8_t type) 
 * registers an *inEvent into the right chain. 
 * @IN: scheduler_t *inEvent: an event specified after scheduler_t
 * @IN: uint8_t type: has the event executed after 0.1ms, 1ms, 10ms, 100ms, 1s
 */
void scheduler_regEvent(scheduler_t *inEvent, uint8_t type) {
	cli();
	switch (type) {
		case EVENT_01:
		inEvent->next = events01;
		events01 = inEvent;
		break;
		case EVENT_1:
		inEvent->next = events1;
		events1 = inEvent;
		break;
		case EVENT_10:
		inEvent->next = events10;
		events10 = inEvent;
		break;
		case EVENT_100:
		inEvent->next = events100;
		events100 = inEvent;
		break;
		case EVENT_1000:
		inEvent->next = events1000;
		events1000 = inEvent;
		break;
	}
	sei();
}


/**
 * void unregEvent(scheduler_t *inEvent, uint8_t type) 
 * unregister an event
 * @IN: scheduler_t *inEvent: a pointer to the event to unregister
 * @IN: uint8_t type: the chain in which the event should occure
 */
void scheduler_unregEvent(scheduler_t *inEvent, uint8_t type) {
	scheduler_t *event;
	scheduler_t *tmp_event;
	
	cli();
	
	switch (type) {
		case EVENT_01:
		event = events01;
		break;
		case EVENT_1:
		event = events1;
		break;
		case EVENT_10:
		event = events10;
		break;
		case EVENT_100:
		event = events100;
		break;
		case EVENT_1000:
		event = events1000;
		break;
		default:
		event = NULL;
	}	
	
	/* to prevent null pointer exception, quit if the event pointer is NULL */
	if ( event == NULL ) {
		sei();
		return;
	}
	
	if (event == inEvent) {
		event = event->next;
	} else {
		tmp_event = event;
		while ( tmp_event != NULL) {
			if ( tmp_event->next == inEvent ) {
				tmp_event->next = tmp_event->next->next;
				break;
			}
			tmp_event = tmp_event->next;
		}
	}
	
	switch (type) {
		case EVENT_01:
		events01 = event;
		break;
		case EVENT_1:
		events1 = event;
		break;
		case EVENT_10:
		events10 = event;
		break;
		case EVENT_100:
		events100 = event;
		break;
		case EVENT_1000:
		events1000 = event;
		break;
	}	
	
	sei();
}


/**
 * void execEvents(scheduler_t *inEvent)
 * executing an event function after the hold time has passed. Afterwards resetting the event counter to 0
 * @IN: scheduler_t *inEvent: the event to execute determined by the timer
 */
void scheduler_execEvents(scheduler_t *inEvent) {
	scheduler_t *tmp_event;
	
	tmp_event = inEvent;
	while (tmp_event != NULL) {
		tmp_event->cur_time++;
		if ( tmp_event->cur_time == tmp_event->exe_time ) {
			if ( tmp_event->func != NULL ) {
				tmp_event->func();
			}
			tmp_event->cur_time = 0;
		}
		tmp_event = tmp_event->next;
	}
}
