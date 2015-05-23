/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Proximity/Infrared
 */

#include <stdint.h>

#include "../../../Core/macros.h"
#include "config.h"
#include "single.h"

#include "../../../ADC/adc.h"


uint16_t sensor_infrared_single_read (uint8_t sensor_id)
{
	uint16_t reading = 0;

	adc_set_channel(sensor_id);
	adc_read(&reading);

	return reading;
	// return ((uint8_t) (reading >= SENSOR_PROXIMITY_INFRARED_THRESHOLD));
}
