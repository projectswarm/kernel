/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Proximity/Infrared
 */

#include <stdint.h>

#include "../../../Core/macros.h"
#include "config.h"
#include "matrix.h"

#include "../../../ADC/adc.h"
#include "single.h"


void sensor_infrared_matrix_read (struct Matrix *matrix)
{
	matrix->ne = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_NORTH_EAST);
	matrix->e  = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_EAST);
	matrix->se = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_SOUTH_EAST);
	matrix->sw = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_SOUTH_WEST);
	matrix->w  = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_WEST);
	matrix->nw = sensor_infrared_single_read(SENSOR_PROXIMITY_INFRARED_NORTH_WEST);
}
