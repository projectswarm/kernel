/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module ADC
 */

#ifndef ADC_ADC_H
#define ADC_ADC_H

enum adc_reference;

enum adc_prescaler;


void adc_initialize (enum adc_reference, enum adc_prescaler);

void adc_disable (void);

void adc_set_channel (uint8_t);

void adc_convert (void);

void adc_read (uint16_t*);

#endif
