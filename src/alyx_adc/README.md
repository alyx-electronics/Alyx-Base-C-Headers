# alyx_adc

## Usage
To use the `alyx_adc` header use:
```c
#include "alyx/adc.h"
```

## Defines

### `ADCVREF`
Define this value when your board does not have the standard ADC Reference Voltage of 3.3V.  
This might be the case when you are using a Alyx Base V2 which has the following value.

```c
#define ADCVREF 4.1f
```

## Functions

### `void alyx_init_adc()`
This function initializes the ADC.

### `uint16_t alyx_get_adc_value(uint gpio)`
This function returns the value of the given GPIO Pin.

### `float alyx_get_adc_voltage(uint gpio)`
This function returns the voltage of the given GPIO Pin in Volt.
