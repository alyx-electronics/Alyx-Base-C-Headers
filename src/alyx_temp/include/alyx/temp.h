#include "hardware/adc.h"

#ifndef ADCVREF
#define ADCVREF 3.3f
#endif

//--------------------------------------------------
// Temp Init related functions
//--------------------------------------------------

void alyx_init_temp() {
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

//--------------------------------------------------
// ADC Value related functions
//--------------------------------------------------

uint16_t alyx_get_temp_value() {
    adc_select_input(4);
    return adc_read();
}

float alyx_get_temp_celsius() {
    adc_select_input(4);
    uint value = adc_read();
    float conversion_factor = ADCVREF / (1 << 12);
    float voltage = value * conversion_factor;

    return (27 - ((voltage - 0.706) / 0.001721));
}
