#include "pico/stdlib.h"
#include <stdio.h>

void alyx_init_serial() {
    stdio_init_all();
}

void alyx_scanf(unsigned char buffer[85]) {
    unsigned char u , *p ;
    for (p=buffer, u = getchar() ; u != EOF && u != '\r' && p - buffer <80 ; u = getchar()) putchar(*p++=u);
    *p = 0 ;
    printf("\n");
}
