/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Proximity/Infrared
 */

#ifndef SENSOR_PROXIMITY_INFRARED_MATRIX_H
#define SENSOR_PROXIMITY_INFRARED_MATRIX_H

struct Matrix
{
	uint16_t ne;
	uint16_t e;
	uint16_t se;
	uint16_t sw;
	uint16_t w;
	uint16_t nw;
};


void sensor_infrared_matrix_read (struct Matrix*);

#endif
