## Usage
To use the `alyx_adc` header use:
```c
#include "alyx/adc.h"
```

## Defines

### `ADCVREF`
This defines the `ADCVREF` to be `3.3f` meaning 3.3V.

## Functions

### Initialization of the ADC

#### `void alyx_init_adc()`
This function initializes the ADC hardware.

### ADC Values

#### `uint16_t alyx_get_adc_value(uint gpio)`
This function initializes the given gpio as an analog input. It reads from the input and returns its value.

#### `float alyx_get_adv_voltage(uint gpio)`
This function initializes the given gpio as an analog input. It reads from the input, calculates the voltage and returns it. 
