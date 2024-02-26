#include "hardware/rtc.h"
#include "hardware/xosc.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"

//--------------------------------------------------
// RTC related functions
//--------------------------------------------------
datetime_t start;
datetime_t current;

void alyx_set_rtc() {
    rtc_init();
    rtc_set_datetime(&start);
}

datetime_t alyx_get_rtc() {
    rtc_get_datetime(&current);
    return current;
}

bool alyx_rtc_running() {
    return rtc_running();
}
//--------------------------------------------------
// Oscilator related functions
//--------------------------------------------------
void alyx_init_crystal() {
    xosc_init();
}

void alyx_disable_crystal() {
    xosc_disable();
}
//--------------------------------------------------
// Clock related functions
//--------------------------------------------------
void alyx_set_clock_48mhz() {
    set_sys_clock_48mhz();
}

bool alyx_set_clock_125mhz() {
    uint32_t freq_khz = 125000;
    uint vco, postdiv1, postdiv2;
    if (check_sys_clock_khz(freq_khz, &vco, &postdiv1, &postdiv2)) {
        set_sys_clock_pll(vco, postdiv1, postdiv2);
        return true;
    }
    return false;
}

bool alyx_set_clock_133mhz() {
    uint32_t freq_khz = 133000;
    uint vco, postdiv1, postdiv2;
    if (check_sys_clock_khz(freq_khz, &vco, &postdiv1, &postdiv2)) {
        set_sys_clock_pll(vco, postdiv1, postdiv2);
        return true;
    }
    return false;
}

//--------------------------------------------------
