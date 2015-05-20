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
#endif
