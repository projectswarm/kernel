#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include "config.h"
#include "encoder.h"

void encoder_interrupt_init(){
	EICRA|=_BV(ISC00)|_BV(ISC10);
	EIMSK|=_BV(INT0)|_BV(INT1);
}

void encoder_read(volatile int counts, volatile struct speed_calc *calc){
	counts++;
	float radians=(counts*(calc->resolution))*M_PI/180;
	pid->position=radians*(calc->radius);
}

void derivate(volatile struct speed_calc *calc){
	calc->speed=(calc->prev_position-calc->position)/calc->h;
	calc->prev_position=calc->position;
}


