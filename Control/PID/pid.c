/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/PID
 */

#include <avr/io.h>
#include <math.h>
#include "pid.h"



uint8_t pidcomputing(volatile struct pidparam *pid, int16_t speed, int16_t cur_speed){

	//Calculating error signal between step value and current value
	pid->error=speed-cur_speed;

	//Summing error for calculating integral part of PID controller
	if(abs(pid->error)>(pid->windupband)){
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

	//Error in previous sample time
	pid->prev_error=pid->error;

	uint8_t control_signal=(Up+Ui+Ud)/100*1.344;
	//Converting control signal to PWM signal
	return control_signal;
}

