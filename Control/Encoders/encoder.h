/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/ENCODERS
 */

#ifndef CONTROL_ENCODERS_ENCODER_H
#define CONTROL_ENCODERS_ENCODER_H

	struct speed_calc{
		float position;
		float prev_position;
		float speed;
		float h;
		int resolution;
		int radius;
	};

	void derivate(volatile struct speed_calc*)

	void encoder_interrupt_init(void);

	float enocoder_read(volatile int, volatile struct speed_calc*);
#endif
