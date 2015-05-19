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


// Circle buffer
char incoming_buffer[COMMUNICATION_USART_BUFFER_SIZE];
uint8_t incoming_buffer_pointer = 0;


void usart_init (void)
{
	// Turn on the transmission and reception circuitry
	UCSRB |= (1 << RXEN) | (1 << TXEN);

	// Using 8-bit word and 1 stop bit
	UCSRB |= (1 << UCSZ0) | (1 << UCSZ1);
	UCSRC |= (1 << UCSZ0) | (1 << UCSZ1);

	// Transmission rate
	UBRRH = (COMMUNICATION_USART_BAUD_PRESCALE >> 8);
	UBRRL = COMMUNICATION_USART_BAUD_PRESCALE;

	// Enable interrupts
	UCSRB |= (1 << RXCIE);
}

void usart_sendbyte (char outgoing_byte)
{
	// Wait for empty transmit buffer
	WAIT_UNTIL_BIT_IS_SET(UCSRA, UDRE);

	// Put the data into buffer
	UDR = outgoing_byte;
}

void usart_sendbytes (char outgoing_bytes[], uint8_t bytes_count)
{
	uint8_t i;

	for (i = 0; i < bytes_count; i++)
		usart_sendbyte(outgoing_bytes[i]);
}

void usart_ssendbytes (char* outgoing_bytes)
{
	uint8_t i;

	for (i = 0; i < strlen(outgoing_bytes); i++)
		usart_sendbyte(outgoing_bytes[i]);
}

void usart_debug (void)
{
	usart_sendbytes(incoming_buffer, COMMUNICATION_USART_BUFFER_SIZE);
}


ISR (USART_RX_vect)
{
	// Save data to circle buffer
	incoming_buffer[incoming_buffer_pointer] = (char) UDR;

	if (incoming_buffer_pointer >= (COMMUNICATION_USART_BUFFER_SIZE - 1))
		incoming_buffer_pointer = 0;
	else
		incoming_buffer_pointer++;
}
