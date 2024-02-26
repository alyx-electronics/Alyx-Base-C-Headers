#include "hardware/uart.h"
#include "hardware/gpio.h"

//--------------------------------------------------
// UART Init related functions
//--------------------------------------------------
void alyx_init_uart(int UART_TX_PIN, int UART_RX_PIN, uart_inst * UART_INTERFACE, uint UART_BAUDRATE) {
    gpio_init(UART_TX_PIN);
    gpio_init(UART_RX_PIN);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_init(UART_INTERFACE, UART_BAUDRATE);
}

void alyx_deinit_uart(int UART_TX_PIN, int UART_RX_PIN, uart_inst * UART_INTERFACE) {
    uart_deinit(UART_INTERFACE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_NULL);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_NULL);
    gpio_deinit(UART_TX_PIN);
    gpio_deinit(UART_RX_PIN);
}

//--------------------------------------------------
// UART Settings related functions
//--------------------------------------------------
void alyx_set_uart_format(uart_inst* UART_INTERFACE, uint UART_DATA_BITS, uint UART_STOP_BITS, uart_parity_t UART_PARITY) {
    uart_set_format(UART_INTERFACE, UART_DATA_BITS, UART_STOP_BITS, UART_PARITY);
}

uint alyx_set_uart_baudrate(uart_inst * UART_INTERFACE, uint UART_BAUDRATE) {
    return uart_set_baudrate(UART_INTERFACE, UART_BAUDRATE);
}

//--------------------------------------------------
// UART Communincation related functions
//--------------------------------------------------
void alyx_write_uart(uart_inst* UART_INTERFACE, uint8_t* MESSAGE) {
    if (uart_is_writeable(UART_INTERFACE)) {
        uart_write_blocking(UART_INTERFACE, MESSAGE, sizeof(MESSAGE));
    }
}

void alyx_read_uart(uart_inst* UART_INTERFACE, uint8_t* MESSAGE, size_t LEN) {
    if (uart_is_readable(UART_INTERFACE)) {
        uart_read_blocking(UART_INTERFACE, MESSAGE, LEN);
    }
}
