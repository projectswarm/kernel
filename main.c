#include <stdint.h>
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
	uint16_t a;

	while (1)
	{
		sensor_infrared_matrix_read(&sensorMatrix);

		// debug("debug message: %d", a);
		/*debug("NE: %d E: %d SE: %d SW: %d W: %d NW: %d ",
				sensorMatrix.ne,
				sensorMatrix.e,
				sensorMatrix.se,
				sensorMatrix.sw,
				sensorMatrix.w,
				sensorMatrix.nw);*/

		int i;

		for (i = 0; i < 9; i++)
		{
			adc_set_channel(i);
			adc_read(&a);

			debug("ADC%d = %d ", i, a);
		}

		/*adc_set_channel(5);
		adc_read(&a);

		debug("ADC5 = %d ", a);

		adc_set_channel(8);
		adc_read(&a);

		debug("ADC8 = %d ", a);*/

		_delay_ms(2000);
	}

	return 0;
}
