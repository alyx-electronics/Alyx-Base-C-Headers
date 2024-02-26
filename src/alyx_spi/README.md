# alyx_spi

## Usage
```c
#include "alyx/spi.h"
```

## Functions

### `void alyx_init_spi(uint SPI_RX_PIN, uint SPI_TX_PIN, uint SPI_SCK_PIN, spi_inst_t* SPI_INTERFACE, uint SPI_BAUDRATE)`
This functions initializes the given `SPI Interafce` with the given `TX Pin`, `RX Pin`, `SCK Pin` and `Baudrate`.

### `void alyx_deinit_spi(uint SPI_RX_PIN, uint SPI_TX_PIN, uint SPI_SCK_PIN, spi_inst_t* SPI_INTERFACE)`
This functions deinitializes the given `SPI Interafce` and the given `TX Pin`, `RX Pin` and `SCK Pin`.

### `void alyx_init_spi_cs(uint SPI_CSN_PIN)`
This functions initializes the given `SPI CS Pin`.

### `void alyx_deinit_spi_cs(uint SPI_CSN_PIN)`
This functions deinitializes the given `SPI CS Pin`.

***

### `void alyx_set_spi_format(spi_inst_t* SPI_INTERFACE, uint SPI_DATA_BITS, spi_cpol_t SPI_CPOL, spi_cpha_t SPI_CPHA)`
To-Do

### `void alyx_set_spi_slave(spi_inst_t* SPI_INTERFACE)`
This function sets the given `SPI Interface` as `Slave`.

### `uint alyx_set_spi_baudrate(spi_inst_t* SPI_INTERFACE, uint SPI_BAUDRATE)`
This function sets the given `Baudrate` and returns the actual `Baudrate` set.

***

### `void alyx_write_spi(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t* MESSAGE)`
This function writes the given `Message` on the given `SPI Interface` and selects the `SPI Slave` on `SPI_CSN`.

### `void alyx_read_spi(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t SPI_RTX, uint8_t* MESSAGE, size_t LEN)`
This function reads on the given `SPI Interface`, stores it in `Message` and selects the `SPI Slave` on `SPI_CSN`.

### `void alyx_write_spi_slave(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t* MESSAGE)`
This function writes the given `Message` on the given `SPI Interface` when selected as `SPI Slave` via `SPI_CSN`.

### `void alyx_read_spi_slave(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t SPI_RTX, uint8_t* MESSAGE, size_t LEN)`
This function reads on the given `SPI Interface` when selected as `SPI Slave` via `SPI_CSN` and stores it in `Message`
