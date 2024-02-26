# alyx_pwm
## Usage

To use the `alyx_pwm` header use:
```c
#include "alyx/pwm.h"
```

## Frequency and Duty Cycle
These values can be calculated with following formulas:
* Frequency of the PWM Signal: `System Clock Frequency` / (`wrap` + 1)  
* Duty Cycle of the PWM Signal: `level` / (`wrap` + 1)

## Functions

### `void alyx_init_pwm(uint gpio, uint16_t wrap)`
This function initializes the PWM on the given GPIO Pin and sets the maximum value of the PWM.  
Valid values for `wrap` are: [0; 65535]

### `void alyx_deinit_pwm(uint gpio)`
This function deinitializes the PWM on the given GPIO Pin.

***

### `uint alyx_get_pwm_slice(uint gpio)`
This function return the PWM Slice of the given GPIO Pin.

### `uint alyx_get_pwm_channel(uint gpio)`
This function return the PWM Channel of the given GPIO Pin.

### `void alyx_set_pwm(uint gpio, uint16_t level)`
This function set the PWM active on the given GPIO Pin and stays `HIGH` for `level` cycles.  
