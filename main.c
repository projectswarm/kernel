#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Core/macros.h"
#include "Core/config.h"

#include "Communication/USART/usart.h"
#include "Core/Debug/debug.h"


int main (void)
{
	sei();
	usart_init();

	while (1)
	{
		// Run bitch, run!
		debug("DEBUG: %s", "hello world!");
		_delay_ms(1000);
	}

	return 0;
}
