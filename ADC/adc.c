/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module ADC
 */

#include <stdint.h>
#include <avr/io.h>

#include "../Core/macros.h"
#include "../Core/config.h"
#include "adc.h"


enum adc_reference { EXTERNAL_VREF = 0,
					EXTERNAL_AVCC,
					INTERNAL = 3 };

enum adc_prescaler { PRESCALE_BY_2 = 0,
					PRESCALE_BY_4 = 2,
					PRESCALE_BY_8,
					PRESCALE_BY_16,
					PRESCALE_BY_32,
					PRESCALE_BY_64,
					PRESCALE_BY_128
};


void adc_initialize (enum adc_reference reference, enum adc_prescaler prescaler)
{
	// Select the reference value
	ADMUX |= (6 << reference);

	// Set the prescaler
	ADCSRA |= prescaler;

	// Turn ADC on
	SETB(ADCSRA, ADEN);
}

void adc_disable (void)
{
	// Turn ADC off
	CLRB(ADCSRA, ADEN);
}

void adc_set_channel (uint8_t channel)
{
	// Set DDR and PORT
	CLRB(DDRC, channel);
	CLRB(PORTC, channel);

	// Set ADMUX
	ADMUX |= channel;
}

void adc_convert (void)
{
	// Start single conversion
	SETB(ADCSRA, ADSC);

	// Wait until conversion is completed
	WAIT_UNTIL_BIT_IS_CLEAR(ADCSRA, ADSC);
}

void adc_read (uint16_t* value)
{
	adc_convert();

	*value = ADCW;
}
