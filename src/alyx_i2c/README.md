## Usage
To use the `alyx_i2c` header use:
```c
#include "alyx/i2c.h"
```

## Variables

### `i2c_inst* I2C_INTERFACE`
This defines the used `I2C Interface`. Valid options are `i2c0` and `i2c1`

## Functions

### Initialization of the I2C Interface

#### `void alyx_init_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst* I2C_INTERFACE, uint I2C_BAUDRATE)`
This function initializes the given `I2C Interface` with the given `SDA Pin`, `SCL Pin` and `Baudrate`.

#### `void alyx_deinit_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst* I2C_INTERFACE)`
This function initializes the given `I2C Interface` and the given `SDA Pin` and `SCL Pin`.

### Settings of the I2C Interface

#### `void alyx_set_i2c_slave(i2c_inst* I2C_INTERFACE, uint I2C_SLAVE_ADR)`
This function sets the given `I2C Interface` as `Slave` with the given `Address`.

#### `uint alyx_set_i2c_baudrate(i2c_inst* I2C_INTERFACE, uint I2C_BAUDRATE)`
This function tries to set the given `Baudrate` on the given `I2C Interface` and returns the `Baudrate` it set.

### Functions of the I2C Interface

#### `void alyx_write_i2c(i2c_inst* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, bool I2C_NO_STOP)`
This function writes the given `Message` to the given `Address` on the given `I2C Interface`. The Variable `I2C_NO_STOP` determines if a second message receives the tag `Start` or `Restart`.

#### `int alyx_read_i2c(i2c_inst* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, size_t LEN, bool I2C_NO_STOP)`
This function reads `LEN` characters from the given `Address` on the given `I2C Interface` and stores it in `Message`. The Variable `I2C_NO_STOP` determines if a second message receives the tag `Start` or `Restart`. The function returns how many characters were read.
