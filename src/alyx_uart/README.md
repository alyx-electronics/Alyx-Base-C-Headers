## Usage
```c
#include "alyx/uart.h"


```
## Values

### `UART_PARITY`
Valid `UART_PARITY`:
* `UART_PARITY_NONE`
* `UART_PARITY_EVEN`
* `UART_PARITY_ODD`

### `UART_INTERFACE`
Valid `UART_INTERFACE`:
* `uart0`
* `uart1`

## Functions

### `void alyx_init_uart(int UART_TX_PIN, int UART_RX_PIN, uart_inst * UART_INTERFACE, uint UART_BAUDRATE)`
This function initilizes the given `UART Interface` with the given `TX` and `RX` Pins and sets the `Baudrate` of the `UART`.

### `void alyx_deinit_uart(int UART_TX_PIN, int UART_RX_PIN, uart_inst * UART_INTERFACE)`
This function deinitilizes the given `UART Interface` with the given `TX` and `RX` Pins.

***

### `void alyx_set_uart_format(uart_inst* UART_INTERFACE, uint UART_DATA_BITS, uint UART_STOP_BITS, uart_parity_t UART_PARITY)`
This function sets the given `Data Bit Count`, `Stop Bit Count` and `Parity`.

### `uint alyx_set_uart_baudrate(uart_inst * UART_INTERFACE, uint UART_BAUDRATE)`
This function sets the given `Baudrate` and returns the actual `Baudrate` set.

***

### `void alyx_write_uart(uart_inst* UART_INTERFACE, uint8_t* MESSAGE)`
This function writes the given `Message` on the given `UART Interface`.

### `void alyx_read_uart(uart_inst* UART_INTERFACE, uint8_t* MESSAGE)`
This function reads  on the given `UART Interface`and stores it in `Message`.
