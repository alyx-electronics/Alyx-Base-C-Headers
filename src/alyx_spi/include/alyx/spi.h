#include "hardware/gpio.h"
#include "hardware/spi.h"

//--------------------------------------------------
// SPI Init related functions
//--------------------------------------------------
void alyx_init_spi(uint SPI_RX_PIN, uint SPI_TX_PIN, uint SPI_SCK_PIN, spi_inst_t* SPI_INTERFACE, uint SPI_BAUDRATE) {
    gpio_init(SPI_RX_PIN);
    gpio_init(SPI_SCK_PIN);
    gpio_init(SPI_TX_PIN);
    gpio_set_function(SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SPI_TX_PIN, GPIO_FUNC_SPI);
    spi_init(SPI_INTERFACE, SPI_BAUDRATE);
}

void alyx_deinit_spi(uint SPI_RX_PIN, uint SPI_TX_PIN, uint SPI_SCK_PIN, spi_inst_t* SPI_INTERFACE) {
    spi_deinit(SPI_INTERFACE);
    gpio_set_function(SPI_RX_PIN, GPIO_FUNC_NULL);
    gpio_set_function(SPI_SCK_PIN, GPIO_FUNC_NULL);
    gpio_set_function(SPI_TX_PIN, GPIO_FUNC_NULL);
    gpio_deinit(SPI_RX_PIN);
    gpio_deinit(SPI_SCK_PIN);
    gpio_deinit(SPI_TX_PIN);
}

void alyx_init_spi_cs(uint SPI_CSN_PIN) {
    gpio_init(SPI_CSN_PIN);
    gpio_set_dir(SPI_CSN_PIN, out);
    gpio_set_function(SPI_CSN_PIN, GPIO_FUNC_SPI);
    
}

void alyx_deinit_spi_cs(uint SPI_CSN_PIN) {
    gpio_set_function(SPI_CSN_PIN, GPIO_FUNC_NULL);
    gpio_deinit(SPI_CSN_PIN);
}

//--------------------------------------------------
// SPI Settings related functions
//--------------------------------------------------
void alyx_set_spi_format(spi_inst_t* SPI_INTERFACE, uint SPI_DATA_BITS, spi_cpol_t SPI_CPOL, spi_cpha_t SPI_CPHA) {
    spi_set_format(SPI_INTERFACE, SPI_DATA_BITS, SPI_CPOL, SPI_CPHA, SPI_MSB_FIRST);
}

void alyx_set_spi_slave(spi_inst_t* SPI_INTERFACE) {
    spi_set_slave(SPI_INTERFACE, true);
}

uint alyx_set_spi_baudrate(spi_inst_t* SPI_INTERFACE, uint SPI_BAUDRATE) {
    return spi_set_baudrate(SPI_INTERFACE, SPI_BAUDRATE);
}

//--------------------------------------------------
// SPI Communincation related functions
//--------------------------------------------------
void alyx_write_spi(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t* MESSAGE) {
    if (spi_is_writable(SPI_INTERFACE)) {
        gpio_put(SPI_CSN_PIN, value);
        spi_write_blocking(SPI_INTERFACE, MESSAGE, sizeof(MESSAGE));
    }
}

void alyx_read_spi(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t SPI_RTX, uint8_t* MESSAGE, size_t LEN) {
    if (spi_is_readable(SPI_INTERFACE)) {
        gpio_put(SPI_CSN_PIN, value);
        spi_read_blocking(SPI_INTERFACE, SPI_RTX, MESSAGE, LEN);
    }
}

void alyx_write_spi_slave(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t* MESSAGE) {
    if (spi_is_writable(SPI_INTERFACE)) {
        if (gpio_get(SPI_CSN_PIN)) {
            spi_write_blocking(SPI_INTERFACE, MESSAGE, sizeof(MESSAGE));
        }
    }
}

void alyx_read_spi_slave(spi_inst_t* SPI_INTERFACE, uint SPI_CSN_PIN, uint8_t SPI_RTX, uint8_t* MESSAGE, size_t LEN) {
    if (spi_is_readable(SPI_INTERFACE)) {
        if (gpio_get(SPI_CSN_PIN)) {
            spi_read_blocking(SPI_INTERFACE, SPI_RTX, MESSAGE, LEN);
        }
    }
}
