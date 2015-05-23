/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/USART
 */

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "../../Core/macros.h"
#include "../../Core/config.h"
#include "config.h"
#include "usart.h"


void usart_init (void)
{
	// Turn on the transmission and reception circuitry
	UCSRB |= _BV(RXEN) | _BV(TXEN);

	// Using 8-bit word and 1 stop bit
	// ATmega324P
	// UCSRB |= (1 << UCSZ0) | (1 << UCSZ1);
	UCSRC |= _BV(UCSZ0) | _BV(UCSZ1);

	// Transmission rate
	UBRRH = (COMMUNICATION_USART_BAUD_PRESCALE >> 8);
	UBRRL = COMMUNICATION_USART_BAUD_PRESCALE;
}

void usart_sendbyte (char outgoing_byte)
{
	// Wait for empty transmit buffer
	WAIT_UNTIL_BIT_IS_SET(UCSRA, UDRE);

	// Put the data into buffer
	UDR = outgoing_byte;
}

void usart_sendbytes_c (char outgoing_bytes[], uint8_t bytes_count)
{
	uint8_t i;

	for (i = 0; i < bytes_count; i++)
		usart_sendbyte(outgoing_bytes[i]);
}

void usart_sendbytes (char* outgoing_bytes)
{
	uint8_t i;

	for (i = 0; i < strlen(outgoing_bytes); i++)
		usart_sendbyte(outgoing_bytes[i]);
}
