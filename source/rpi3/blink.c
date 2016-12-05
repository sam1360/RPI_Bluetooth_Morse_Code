#include <wiringPi.h>
#include <stdint.h>

#include "rpi3/blink.h"

void blink_once(void)
{
    // Turn on GPIO 17
    digitalWrite( 0, HIGH );

    delay(500);

    // Turn off GPIO 17
    digitalWrite( 0, LOW );

    delay(500);
}

void blink_code(uint32_t err)
{
    for(uint32_t i = 0; i < err; ++i)
    {
        blink_once();
    }

    // Only delay 4 seconds, since we delay for 1 additional
    // second in blink_once().
    delay(4500);
}

void blink_for(uint32_t duration)
{
    // Turn on GPIO 17
    digitalWrite( 0, HIGH );

    delay(duration);

    // Turn off GPIO 17
    digitalWrite( 0, LOW );
}

void blink_on(void)
{
    digitalWrite( 0, HIGH );
}

void blink_off(void)
{
    digitalWrite( 0, LOW );
}
