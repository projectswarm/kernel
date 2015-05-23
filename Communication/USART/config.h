/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/USART
 */

#ifndef COMMUNICATION_USART_CONFIG_H
#define COMMUNICATION_USART_CONFIG_H

#define COMMUNICATION_USART_BAUD_RATE 4800
#define COMMUNICATION_USART_BAUD_PRESCALE (((F_CPU / (COMMUNICATION_USART_BAUD_RATE * 16UL))) - 1)

#ifdef CPU_TYPE_ATMEGA324P
	#define UCSRA         UCSR0A
	#define UCSRB         UCSR0B
	#define UCSRC         UCSR0C
	#define UBRRH         UBRR0H
	#define UBRRL         UBRR0L
	#define UDR           UDR0
	#define USART_RX_vect USART0_RX_vect

	#define UDRE          UDRE0
	#define RXEN          RXEN0
	#define TXEN          TXEN0
	#define UCSZ0         UCSZ00
	#define UCSZ1         UCSZ01
	#define RXCIE         RXCIE0
#endif

#ifdef CPU_TYPE_ATMEGA328P
	#define UCSRA         UCSR0A
	#define UCSRB         UCSR0B
	#define UCSRC         UCSR0C
	#define UBRRH         UBRR0H
	#define UBRRL         UBRR0L
	#define UDR           UDR0

	#define UDRE          UDRE0
	#define RXEN          RXEN0
	#define TXEN          TXEN0
	#define UCSZ0         UCSZ00
	#define UCSZ1         UCSZ01
	#define RXCIE         RXCIE0
#endif

#endif
