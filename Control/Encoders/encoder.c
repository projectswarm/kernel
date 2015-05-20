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
	EICRA|=_BV(ISC00)|_BV(ISC10);
	EIMSK|=_BV(INT0)|_BV(INT1);
}

//Converting counted impulse to traveled position
void encoder_read(volatile int c, volatile struct speed_calc *calc){
	float radians=(c*(calc->resolution))*M_PI/180;
	pid->position=radians*(calc->radius);
}

//Numerical calucation of position derivative
void derivate(volatile struct speed_calc *calc){
	calc->speed=(calc->prev_position-calc->position)/calc->h;
	calc->prev_position=calc->position;
}


