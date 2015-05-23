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


void adc_init (enum adc_reference reference, enum adc_prescaler prescaler)
{
	// Select the reference value
	// ADMUX |= (6 << reference);
	// ADMUX = (1 << REFS1) | (1 << REFS0);
	ADMUX = (1 << REFS0);

	// Set the prescaler
	// ADCSRA |= prescaler;
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

	// Turn ADC on
	ADCSRA |= _BV(ADEN);
}

void adc_disable (void)
{
	// Turn ADC off
	ADCSRA &= ~_BV(ADEN);
}

void adc_set_channel (uint8_t channel)
{
	channel &= 0b00001111;

	// Set DDR and PORT
	// CLRB(DDRC, channel);
	// CLRB(PORTC, channel);

	// Set ADMUX
	ADMUX = (ADMUX & 0xF0) | channel;
}

void adc_convert (void)
{
	// Start single conversion
	ADCSRA |= _BV(ADSC);

	// Wait until conversion is completed
	WAIT_UNTIL_BIT_IS_CLEAR(ADCSRA, ADSC);
}

void adc_read (uint16_t* value)
{
	adc_convert();

	*value = ADCW;
}
