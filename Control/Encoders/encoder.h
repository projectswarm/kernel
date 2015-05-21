/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Control/ENCODERS
 */

#ifndef CONTROL_ENCODERS_ENCODER_H
#define CONTROL_ENCODERS_ENCODER_H

	struct speed_calc{
		float position_left;
		float prev_position_left;
		float speed_left;
		float position_right;
		float prev_position_right;
		float speed_right;
		float h;
		int resolution;
		int radius;
	};

	void derivate(volatile struct speed_calc*);

	void encoder_interrupt_init(void);

	float enocoder_read(volatile int*, volatile struct speed_calc*);
#endif
