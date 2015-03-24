/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Proximity/Infrared
 */

#include <stdint.h>

#include "../../../Core/macros.h"
#include "../../../ADC/adc.h"
#include "config.h"


void sensor_infrared_matrix_read (uint8_t readings[3][2])
{
	readings[0][1] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_NORTH_EAST);
	readings[1][1] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_EAST);
	readings[2][1] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_SOUTH_EAST);
	readings[2][0] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_SOUTH_WEST);
	readings[1][0] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_WEST);
	readings[0][0] = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_NORTH_WEST);
}
