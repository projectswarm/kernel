/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/ENCODERS
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include "config.h"
#include "encoder.h"

//ISR Initializing
void encoder_interrupt_init(){
	EICRA|=(_BV(ISC00)|_BV(ISC10));
	EIMSK|=(_BV(INT0)|_BV(INT1));
}

void encoder_timer_init(){
	TCCR1A|=_BV(COM1A0);
	TCCR1B|=(_BV(CS11)|_BV(CS10));
	OCR1A=3125;
	TIMSK1|=_BV(OCIE1A);
}


//Converting counted impulse to traveled position
void encoder_read(volatile int *c, volatile struct speed_calc *calc){
	float radians_left=(c[0]*(calc->resolution))*M_PI/180;
	float radians_right=(c[1]*(calc->resolution))*M_PI/180;
	calc->position_left=radians_left*(calc->radius);
	calc->position_right=radians_right*(calc->radius);
}

//Numerical calucation of position derivative
void derivate(volatile struct speed_calc *calc){
	//Left wheel speed
	calc->speed_left=(calc->prev_position_left-calc->position_left)/calc->h;
	calc->prev_position_left=calc->position_left;

	//Right wheel speed
	calc->speed_right=(calc->prev_position_right-calc->position_right)/calc->h;
	calc->prev_position_right=calc->position_right;
}


