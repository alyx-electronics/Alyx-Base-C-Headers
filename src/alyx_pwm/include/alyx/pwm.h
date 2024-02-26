#include "hardware/pwm.h"
#include "hardware/gpio.h"

//--------------------------------------------------
// PWM Init related functions
//--------------------------------------------------

void alyx_init_pwm(uint gpio, uint16_t wrap) {
    gpio_init(gpio);
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    pwm_set_wrap(pwm_gpio_to_slice_num(gpio), wrap);
}

void alyx_deinit_pwm(uint gpio) {
    pwm_set_enabled(pwm_gpio_to_slice_num(gpio), false);
    gpio_set_function(gpio, GPIO_FUNC_NULL);
    gpio_deinit(gpio);
}

//--------------------------------------------------
// PWM related functions
//--------------------------------------------------

uint alyx_get_pwm_slice(uint gpio) {
    return pwm_gpio_to_slice_num(gpio);
}

uint alyx_get_pwm_channel(uint gpio) {
    return pwm_gpio_to_channel(gpio);
}

void alyx_set_pwm(uint gpio, uint16_t level) {
    pwm_set_gpio_level(gpio, level);
    pwm_set_enabled(pwm_gpio_to_slice_num(gpio), true);
}
