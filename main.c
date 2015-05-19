#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Core/macros.h"
#include "Core/config.h"

#include "Communication/USART/usart.h"
#include "Core/Debug/debug.h"
#include "ADC/adc.h"
#include "Sensor/Proximity/Infrared/matrix.h"


int main (void)
{
	sei();
	usart_init();
	adc_init(INTERNAL, PRESCALE_BY_2);

	struct Matrix sensorMatrix;

	while (1)
	{
		sensor_infrared_matrix_read(&sensorMatrix);

		debug("NE: %d E: %d SE: %d SW: %d W: %d NW: %d\n",
				sensorMatrix.ne,
				sensorMatrix.e,
				sensorMatrix.se,
				sensorMatrix.sw,
				sensorMatrix.w,
				sensorMatrix.nw);

		_delay_ms(500);
	}

	return 0;
}
