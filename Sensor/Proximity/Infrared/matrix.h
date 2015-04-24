/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Proximity/Infrared
 */

#ifndef SENSOR_PROXIMITY_INFRARED_MATRIX_H
#define SENSOR_PROXIMITY_INFRARED_MATRIX_H

struct Matrix {
	uint8_t ne;
	uint8_t e;
	uint8_t se;
	uint8_t sw;
	uint8_t w;
	uint8_t nw;
};


void sensor_infrared_matrix_read (struct Matrix*);

#endif
