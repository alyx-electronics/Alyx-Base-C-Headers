## Usage

To use the `alyx_time` header use:
```c
#include "alyx/time.h"
```

## Functions

### RTC

#### `void alyx_set_rtc()`
To use this function call it after setting the start date in the `datetime_t` structure.
```c
#include "alyx/time.h"

void main() {
    start.year  = 2024;
    start.month = 4;
    start.day   = 17;
    start.dotw  = 3; // 0 is Sunday, so 5 is Friday
    start.hour  = 0;
    start.min   = 0;
    start.sec   = 0;

    alyx_set_rtc();
};
```

#### `datetime_t alyx_get_rtc()`
To use this function either call it like this:
```c
#include "alyx/time.h"

void main() {
    alyx_get_rtc();

    printf("%d", current.year);
    printf("%d", current.month);
    printf("%d", current.day);
};
```
or like this: 
```c
#include "alyx/time.h"

void main() {

    datetime_t result;
    result = alyx_get_rtc();
};
```

#### `bool alyx_rtc_running()`
This functions returns `true` when the onboard rtc is running, else `false`.

### Initialization of the Crystal Oscillator

#### `void alyx_init_crystal()`
This function initializes the onboard crystal oscillator and waits for it to stabalize to its frequency of 12MHz.

#### `void alyx_disable_crystal()`
This function deinitializes the onboard crystal oscillator and waits for it to unstabalize.

### System Clock Speed

#### `void alyx_set_clock_48mhz()`
This function sets the sysclock frequency to 48 MHz.

#### `bool alyx_set_clock_125mhz()`
This function tries to set the sysclock frequency to 125 MHz and returns `True` or `False`.

#### `bool alyx_set_clock_133mhz()`
This function tries to set the sysclock frequency to 133 MHz and returns `True` or `False`.
