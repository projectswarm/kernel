/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/USART
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#include "../../Core/macros.h"
#include "../../Core/config.h"
#include "config.h"
#include "usart.h"


// Circle buffer
char incoming_buffer[COMMUNICATION_USART_BUFFER_SIZE] = {'a', 'b', 'C', 'd'};
uint8_t incoming_buffer_pointer = 0;


void usart_init (void)
{
	// Turn on the transmission and reception circuitry
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

	// Using 8-bit word and 1 stop bit
	UCSR0B |= (1 << UCSZ00) | (1 << UCSZ01);
	UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);

	// Transmission rate
	UBRR0H = (COMMUNICATION_USART_BAUD_PRESCALE >> 8);
	UBRR0L = COMMUNICATION_USART_BAUD_PRESCALE;

	// Enable interrupts
	UCSR0B |= (1 << RXCIE0);
}

void usart_sendbyte (char outgoing_byte)
{
	// Wait for empty transmit buffer
	WAIT_UNTIL_BIT_IS_SET(UCSR0A, UDRE0);

	// Put the data into buffer
	UDR0 = outgoing_byte;
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


ISR (USART0_RX_vect)
{
	// Save data to circle buffer
	incoming_buffer[incoming_buffer_pointer] = (char) UDR0;

	if (incoming_buffer_pointer >= (COMMUNICATION_USART_BUFFER_SIZE - 1))
		incoming_buffer_pointer = 0;
	else
		incoming_buffer_pointer++;
}
