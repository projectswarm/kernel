/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#ifndef CONTROL_PID_PID_H
#define CONTROL_PID_PID_H

struct pidparam{
	int16_t Kp; //Proportion gain mulitply by 100
	int16_t Ti; //Integral gain mulitply by 100
	int16_t Td; //Derivate gain mulitply by 100
	int16_t Ts; //Inverted sample time (e.g 0.5s is equal to 2s)
	int16_t windupmax; //Wind-up upper limit
	int16_t windupmin; //Wind-up lower limit
	int16_t prev_error; //Previous measured error
	int16_t error; //Current error
	int16_t windupband; //Integral opreating band
	int16_t istate; //Integral summing state
};

uint8_t pidcomputing(volatile struct pidparam* pid, int16_t, int16_t);

#endif
