#include <stdlib.h>
#include <wiringPi.h>

#include "bt-receive/converter.h"
#include "bt-receive/blink_morse.h"
#include "test/test_blink_morse.h"

void test_blink_morse(void) {
    Morse * codes = build_code_table();
    const char * input = "Morse Code";
    blink_signal_from_input( input, codes );
    destroy_code_table( codes );
}
