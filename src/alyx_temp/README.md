# alyx_temp

## Usage
To use the `alyx_temp` header use:
```c
#include "alyx/temp.h"
```

## Defines

### `ADCVREF`
Define this value when your board does not have the standard ADC Reference Voltage of 3.3V.  
This might be the case when you are using a Alyx Base V2 which has the following value.

```c
#define ADCVREF 4.1f
```

## Functions

### `void alyx_init_temp()`
This function initializes the temperature sensor.

### `uint16_t alyx_get_temp_value()`
This function returns the value of the temperature sensor.

### `float alyx_get_temp_celsius()`
This function returns the temperature of the temperature sensor in degrees celsius.
