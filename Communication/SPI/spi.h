/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/SPI
 */

#ifndef COMMUNICATION_SPI_SPI_H
#define COMMUNICATION_SPI_SPI_H

enum spi_role;


void spi_init (enum spi_role);

unsigned char spi_transmit (unsigned char);

#endif
