/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#ifndef CONTROL_PID_PID_H
#define CONTROL_PID_PID_H

struct PIDParam
{
	uint16_t Kp; // Proportion gain multiplied by 100
	uint16_t Ti; // Integral gain multiplied by 100
	uint16_t Td; // Derivative gain multiplied by 100
	uint16_t Ts; // Inverted sample time (e.g 0.5s is equal to 2s)
	uint16_t windupMax; // Wind-up upper limit
	uint16_t windupMin; // Wind-up lower limit
	uint16_t prev_error; // Previous measured error
	uint16_t error; // Current error
	uint16_t windupBand; // Integral operating band
	uint16_t istate; // Integral summing state

	float *controlsignal; // Control signal of PID controller
};


void control_pid_compute (volatile struct PIDParam*, uint16_t, uint16_t);

#endif
