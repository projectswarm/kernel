/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/SHARP
 */

#include <stdint.h>

#include "../../../Core/macros.h"
#include "config.h"
#include "sharp.h"

#include "../../../ADC/adc.h"


void sensor_sharp_read (uint16_t *distance)
{
	uint16_t reading;

	adc_set_channel(SENSOR_SHARP_CHANNEL);
	adc_read(&reading);

	// Do some calculations here
	*distance = reading;
}
