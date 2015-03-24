/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module Kernel/ADC
 */

enum adc_reference;

enum adc_prescaler;


void adc_initialize (enum adc_reference, enum adc_prescaler);

void adc_disable (void);

void adc_set_channel (uint8_t);

void adc_start_conversion (void);

void adc_read (uint16_t*);
