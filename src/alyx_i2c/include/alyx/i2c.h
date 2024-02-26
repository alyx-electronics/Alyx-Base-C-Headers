#include "hardware/gpio.h"
#include "hardware/i2c.h"

//--------------------------------------------------
// I2C Init related functions
//--------------------------------------------------
void alyx_init_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst_t * I2C_INTERFACE, uint I2C_BAUDRATE) {
    gpio_init(I2C_SDA_PIN);
    gpio_init(I2C_SCL_PIN);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    i2c_init(I2C_INTERFACE, I2C_BAUDRATE);
}

void alyx_deinit_i2c(int I2C_SDA_PIN, int I2C_SCL_PIN, i2c_inst_t * I2C_INTERFACE) {
    i2c_deinit(I2C_INTERFACE);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_deinit(I2C_SDA_PIN);
    gpio_deinit(I2C_SCL_PIN);
}

//--------------------------------------------------
// I2C Settings related functions
//--------------------------------------------------
void alyx_set_i2c_slave(i2c_inst_t* I2C_INTERFACE, uint I2C_SLAVE_ADR) {
    i2c_set_slave_mode(I2C_INTERFACE, true, I2C_SLAVE_ADR);
}

uint alyx_set_i2c_baudrate(i2c_inst_t* I2C_INTERFACE, uint I2C_BAUDRATE) {
    return i2c_set_baudrate(I2C_INTERFACE, I2C_BAUDRATE);
}

//--------------------------------------------------
// I2C Communincation related functions
//--------------------------------------------------
void alyx_write_i2c(i2c_inst_t* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, bool I2C_NO_STOP) {
    i2c_write_blocking(I2C_INTERFACE, I2C_ADDR, MESSAGE, sizeof(MESSAGE), I2C_NO_STOP);
}

int alyx_read_i2c(i2c_inst_t* I2C_INTERFACE, uint8_t I2C_ADDR, uint8_t* MESSAGE, size_t LEN, bool I2C_NO_STOP) {
    return i2c_read_blocking(I2C_INTERFACE, I2C_ADDR, MESSAGE, LEN, I2C_NO_STOP);
}
