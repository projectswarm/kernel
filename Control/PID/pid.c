/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#include <stdint.h>
#include <stdlib.h>

#include "pid.h"


void control_pid_compute (volatile struct PIDParam *pid, uint16_t speed, uint16_t cur_speed)
{
	// Calculating error signal between step value and current value
	pid->error = speed - cur_speed;

	// Summing error for calculating integral part of PID controller
	if (abs(pid->error) > pid->windupBand)
	{
		pid->istate = pid->istate + pid->error;
	}

	// Calculating proportional gain
	uint16_t Up = pid->error * pid->Kp;

	// Calculating integral gain
	uint16_t Ui = pid->istate * (pid->Kp / (pid->Ti * pid->Ts));

	// Anti Wind-up
	if (Ui > pid->windupMax)
		Ui = pid->windupMax;

	if (Ui < pid->windupMin)
		Ui = pid->windupMin;

	// Calculating derivative gain
	uint16_t Ud = (pid->Kp * pid->Td * pid->Ts) * (pid->error - pid->prev_error);

	// Converting control signal to PWM signal
	*pid->controlsignal = (Up + Ui + Ud) / 100 *88.6;

	// Error in previous sample time
	pid->prev_error = pid->error;
}

