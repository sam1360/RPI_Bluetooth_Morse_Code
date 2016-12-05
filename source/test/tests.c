#include <wiringPi.h>

#include "test/test_converter.h"
#include "test/test_blink.h"
#include "test/test_blink_morse.h"

int main(void) {
    wiringPiSetup();
    pinMode( 0, OUTPUT );

    test_converter();
    /* test_blink(); */
    test_blink_morse();
    return 0;
}
