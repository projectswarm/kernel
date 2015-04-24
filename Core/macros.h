/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Kernel/Core
 */

#ifndef CORE_MACROS_H
#define CORE_MACROS_H

// Set or clear single bit in Special Function Register
#define SETB(sfr, bit) ((sfr) |= (1 << (bit)))
#define CLRB(sfr, bit) ((sfr) &= ~(1 << (bit)))

// Wait until bit in SFR is set
#define WAIT_UNTIL_BIT_IS_SET(sfr, bit)   while ( ! (sfr & (1 << bit)))
#define WAIT_UNTIL_BIT_IS_CLEAR(sfr, bit) while (sfr & (1 << bit))

#endif
