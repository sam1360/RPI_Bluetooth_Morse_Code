#include <stdint.h>
#include <wiringPi.h>

#include "rpi3/blink.h"

#include "test/test_blink.h"

void test_blink(void) {
    wiringPiSetup();
    pinMode( 0, OUTPUT );

    blink_on();
    delay(500);
    blink_off();
}
