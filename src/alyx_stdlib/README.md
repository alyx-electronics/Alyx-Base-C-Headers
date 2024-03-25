# alyx_stdlib

## Usage
To use the `alyx_stdlib` header use:
```c
#include "alyx/stdlib.h"
```

## Functions

### Serial Functions

#### `void alyx_init_serial()`
This function initializes serial over UART and USB.

#### `void alyx_scanf(unsigned char buffer[85])`
This function reads from the serial stdin and returns the string.