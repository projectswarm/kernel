/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#include <math.h>
#include "pid.h"





void pidcomputing(volatile struct pidparam *pid, uint16_t speed, uint16_t cur_speed){

	//Calculating error signal between step value and current value
	pid->error=speed-cur_speed;

	//Summing error for calculating integral part of PID controller
	if(abs(pid->error)>pid->windupband){
		pid->istate=pid->istate+pid->error;
	}

	//Calcualting proportional gain
	uint16_t Up=pid->error*(pid->Kp);

	//Calculating integral gain
	uint16_t Ui=(pid->istate)*(pid->Kp/(pid->Ti*(pid->Ts)));

	//Anti Wind-up
	if(Ui>pid->windupmax){
		Ui=pid->windupmax;
	}

	if(Ui<pid->windupmin){
		Ui=pid->windupmin;
	}

	//Calculating derivate gain
	uint16_t Ud=((pid->Kp)*(pid->Td)*(pid->Ts))*(pid->error-pid->prev_error);

	//Converting control signal to PWM signal
	pid->controlsignal=(Up+Ui+Ud)/100*88.56;

	//Error in previous sample time
	pid->prev_error=pid->error;
}

