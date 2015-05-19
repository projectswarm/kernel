/*
 * SWARM
 * System of Wide-Applicable Robotics Modules
 *
 * @module ADC
 */

#ifndef ADC_ADC_H
#define ADC_ADC_H

enum adc_reference { EXTERNAL_VREF = 0,
					EXTERNAL_AVCC,
					INTERNAL = 3 };

enum adc_prescaler { PRESCALE_BY_2 = 0,
					PRESCALE_BY_4 = 2,
					PRESCALE_BY_8,
					PRESCALE_BY_16,
					PRESCALE_BY_32,
					PRESCALE_BY_64,
					PRESCALE_BY_128
};


void adc_init (enum adc_reference, enum adc_prescaler);

void adc_disable (void);

void adc_set_channel (uint8_t);

void adc_convert (void);

void adc_read (uint16_t*);

#endif
