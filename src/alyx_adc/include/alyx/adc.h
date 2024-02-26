#include "hardware/adc.h"

#ifndef ADCVREF
#define ADCVREF 3.3f
#endif

//--------------------------------------------------
// ADC Init related functions
//--------------------------------------------------

void alyx_init_adc() {
    adc_init();
}

//--------------------------------------------------
// ADC Value related functions
//--------------------------------------------------

uint16_t alyx_get_adc_value(uint gpio) {
    uint adc_pin = gpio - 26;
    
    adc_gpio_init(gpio);
    adc_select_input(adc_pin);
    return adc_read();
}

float alyx_get_adc_voltage(uint gpio) {
    uint adc_pin = gpio - 26;
    float conversion_factor = ADCVREF / (1 << 12)
    
    adc_gpio_init(gpio);
    adc_select_input(adc_pin);
    uint value = adc_read();

    return (value * conversion_factor);
}
