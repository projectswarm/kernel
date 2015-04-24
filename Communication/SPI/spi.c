/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/SPI
 */

#include <stdint.h>
#include <avr/io.h>

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
	}
}

unsigned char spi_transmit (unsigned char data)
{
	// Data to send
	SPDR = data;

	// Send data
	WAIT_UNTIL_BIT_IS_SET(SPSR, SPIF);

	// Read incoming data
	return SPDR;
}
