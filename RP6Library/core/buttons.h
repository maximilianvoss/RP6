#ifndef __CORE_BUTTONS_H__
#define __CORE_BUTTONS_H__

/* special functions for disabling and enabling buttons or functionalities */
#define enableResetButton(); ({PORTB &= ~START; DDRB |= START;})

#endif

