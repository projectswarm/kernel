/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Core/Debug
 */

#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>

#include "../../Core/macros.h"
#include "../../Core/config.h"
#include "config.h"
#include "debug.h"

#include "../../Communication/USART/usart.h"


void debug (char* message)
{
	//char buffer[CORE_DEBUG_BUFFER_SIZE];
	//sprintf_P(buffer, PSTR("DEBUG: %s"), message);

	usart_ssendbytes(message);
}
