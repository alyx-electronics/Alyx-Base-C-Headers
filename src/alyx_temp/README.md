## Usage
To use the `alyx_temp` header use:
```c
#include "alyx/temp.h"
```

## Defines

### `ADCVREF`
This defines the `ADCVREF` to be `3.3f` meaning 3.3V.

## Functions

### Initialization of the Temperature Sensor

#### `void alyx_init_temp()`
This function initializes the temperature sensor.

### Temperature Values

#### `uint16_t alyx_get_temp_value()`
This function selects the sensor as an analog input, reads it and returns its value.

#### `float alyx_get_temp_celsius()`
This function selects the sensor as an analog input, reads it, calculates the celsius value and returns it. 
