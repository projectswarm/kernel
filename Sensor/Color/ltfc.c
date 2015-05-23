/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Sensor/Color
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/atomic.h>

#include "../../Core/macros.h"
#include "../../Core/config.h"
#include "config.h"


volatile uint16_t period = 0;


void sensor_color_ltfc_init (void)
{
	// Set ICP filtering and detecting rising edge
	TCCR1B = _BV(ICNC1) | _BV(ICES1);

	// Set the prescaler - 64
	TCCR1B |= _BV(CS11) | _BV(CS10);

	// Enable interrupts: ICP and timer overflow
	TIMSK1 = _BV(ICIE1) | _BV(TOIE1);
}

void sensor_color_ltfc_read (uint16_t* frequency)
{
	uint16_t current_period;

	ATOMIC_BLOCK (ATOMIC_FORCEON)
	{
		current_period = period;
	}

	// Compute frequency using F_CPU and prescaler value
	*frequency = F_CPU / 64 / current_period;
}



ISR (TIMER1_OVF_vect)
{

}

ISR (TIMER1_CAPT_vect)
{
	// Rising edge
	if (TCCR1B & _BV(ICES1))
	{
		// Reset prescaler
		GTCCR = _BV(PSRSYNC);

		// Reset counter
		TCNT1 = 0;

		// Save period of the signal
		period = ICR1;
	}
}
