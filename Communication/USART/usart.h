/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Communication/USART
 */

#ifndef COMMUNICATION_USART_USART_H
#define COMMUNICATION_USART_USART_H

void usart_init (void);
void usart_sendbyte (char);
void usart_sendbytes_c (char[], uint8_t);
void usart_sendbytes (char*);

#endif
