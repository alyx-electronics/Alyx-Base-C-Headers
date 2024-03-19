#include "hardware/gpio.h"

//--------------------------------------------------
// GPIO Funtion related functions
//--------------------------------------------------

void alyx_set_gpio_function(uint gpio, enum gpio_function fn) {
    gpio_set_function(gpio, fn);
}

enum gpio_function alyx_get_gpio_funtion(uint gpio) {
    return gpio_get_function(gpio);
}

//--------------------------------------------------
// GPIO Init related functions
//--------------------------------------------------

void alyx_init_gpio(uint gpio) {
    gpio_init(gpio);
}

void alyx_deinit_gpio(uint gpio) {
    gpio_deinit(gpio);
}

//--------------------------------------------------
// GPIO Direction related functions
//--------------------------------------------------

void alyx_set_gpio_direction(uint gpio, bool out) {
    gpio_set_dir(gpio, out);
}

uint alyx_get_gpio_direction(uint gpio) {
    return gpio_get_dir(gpio);
}

//--------------------------------------------------
// GPIO Pull related functions
//--------------------------------------------------

void alyx_set_gpio_pull(uint gpio, bool up) {
    if (up) {
        gpio_pull_up(gpio);
    }
    else {
        gpio_pull_down(gpio);
    }
}

void alyx_unset_gpio_pull(uint gpio) {
    gpio_disable_pulls(gpio);
}

//--------------------------------------------------
// GPIO Value related functions
//--------------------------------------------------
void alyx_set_gpio_value(uint gpio, bool value) {
    gpio_put(gpio, value);
}

bool alyx_get_gpio_value(uint gpio) {
    return gpio_get(gpio);
}
