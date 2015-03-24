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


uint8_t sensor_infrared_single_read (uint8_t sensor_id)
{
	uint16_t reading = 0;

	adc_set_channel(sensor_id);
	adc_read(&reading);

	return (reading >= SENSOR_PROXIMITY_INFRARED_CALIBRATION)
			? 1
			: 0;
}
