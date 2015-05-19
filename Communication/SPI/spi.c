/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/SPI
 */

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "../../Core/macros.h"
#include "../../Core/config.h"
#include "config.h"
#include "spi.h"


enum spi_role { MASTER, SLAVE };


void spi_init (enum spi_role role)
{
	if (role == MASTER)
	{
		// Set SCK and MOSI as output
		SETB(DDRB, COMMUNICATION_SPI_SCK);
		SETB(DDRB, COMMUNICATION_SPI_MOSI);

		// Enable SPI
		SETB(SPCR, SPE);

		// Set as MASTER
		SETB(SPCR, MSTR);
	}
	else
	{
		// Set MISO as output
		SETB(DDRB, COMMUNICATION_SPI_MISO);

		// Enable SPI
		SETB(SPCR, SPE);

		// Enable interrupts (for SLAVE only)
		SETB(SPCR, SPIE);
	}
}

char spi_sendbyte (char outgoing_byte)
{
	// Data to send
	SPDR = outgoing_byte;

	// Exchange data
	// MASTER device waits until outgoing transmission is completed
	// SLAVE device will wait for incoming transmission
	WAIT_UNTIL_BIT_IS_SET(SPSR, SPIF);

	// Read incoming data
	return SPDR;
}


ISR (SPI_STC_vect)
{
	// Read incoming byte and send back appropriate sensor reading
}
