# alyx_gpio

## Usage

To use the `alyx_gpio` header use:
```c
#include "alyx/gpio.h"
```

## Functions

### `void alyx_set_gpio_function(uint gpio, enum gpio_function fn)`
This function sets the function of the given GPIO Pin.  
Valid functions are:
* GPIO_FUNC_XIP
* GPIO_FUNC_SPI
* GPIO_FUNC_UART
* GPIO_FUNC_I2C
* GPIO_FUNC_PWM
* GPIO_FUNC_SIO
* GPIO_FUNC_PIO0
* GPIO_FUNC_PIO1
* GPIO_FUNC_GPCK
* GPIO_FUNC_USB
* GPIO_FUNC_NULL

### `enum gpio_function alyx_get_gpio_funtion(uint gpio)`
This function returns the function of the given GPIO Pin. 

***

### `void alyx_init_gpio(uint gpio)`
This function initializes the given GPIO Pin.

### `void alyx_deinit_gpio(uint gpio)`
This function deinitializes the given GPIO Pin.

***

### `void alyx_set_gpio_direction(uint gpio, bool out)`
This function sets the direction of the given GPIO Pin. `GPIO_OUT` means `Out` and `GPIO_IN` means `In`.

### `uint alyx_get_gpio_direction(uint gpio)`
This function returns the direction of the given GPIO Pin. `1` means `Out` and `0` means `In`.

***

### `void alyx_set_gpio_value(uint gpio, bool value)`
This function sets the value of the given GPIO Pin. `true` means `HIGH` and `false` means `LOW`.

### `bool alyx_get_gpio_value(uint gpio)`
This function returns the value of the given GPIO Pin. `true` means `HIGH` and `false` means `LOW`.
