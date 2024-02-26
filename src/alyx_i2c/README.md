# alyx_i2c

## Usage
```c
#include "alyx/i2c.h"
```

## Variables

### `i2x_inst* I2C_INTERFACE`
Valid values:
* `i2c0`
* `i2c1`


## Functions

### `void alyx_init_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst * I2C_INTERFACE, uint I2C_BAUDRATE)`
This functions initializes the given `I2C Interafce` with the given `SDA Pin`, `SCL Pin` and `Baudrate`.

### `void alyx_deinit_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst * I2C_INTERFACE)`
This functions deinitializes the given `I2C Interafce` and the given `SDA Pin`and `SCL Pin`.

***

### `void alyx_set_i2c_slave(i2c_inst* I2C_INTERFACE, uint I2C_SLAVE_ADR)`
This function sets the given `I2C Interface` as `Slave` with the given `Address`.

### `uint alyx_set_i2c_baudrate(i2c_inst* I2C_INTERFACE, uint I2C_BAUDRATE)`
This function sets the given `Baudrate` of the given `I2C Interface`.

***

### `void alyx_write_i2c(i2c_inst* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, bool I2C_NO_STOP)`
This function writes the given `Message` to the given `Address` on the given `I2C Interface`. The Variable `I2C_NO_STOP` determines if a second message receives the tag `Start` or `Restart`.

### `void alyx_read_i2c(i2c_inst* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, bool I2C_NO_STOP)`
This function reads the given `Address` on the given `I2C Interface` and writes it to the given `Message`. The Variable `I2C_NO_STOP` determines if a second message receives the tag `Start` or `Restart`.
