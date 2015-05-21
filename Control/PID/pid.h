/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#ifndef CONTROL_PID_PID_H
#define CONTROL_PID_PID_H

	 struct pidparam{
		uint16_t Kp; //Proportion gain mulitply by 100
		uint16_t Ti; //Integral gain mulitply by 100
		uint16_t Td; //Derivate gain mulitply by 100
		uint16_t Ts; //Inverted sample time (e.g 0.5s is equal to 2s)
		uint16_t windupmax; //Wind-up upper limit
		uint16_t windupmin; //Wind-up lower limit
		uint16_t prev_error; //Previous measured error
		uint16_t error; //Current error
		uint16_t windupband; //Integral opreating band
		uint16_t istate; //Integral summing state
	};

	 uint8_t pidcomputing(volatile struct pidparam* pid, uint16_t, uint16_t);
#endif
