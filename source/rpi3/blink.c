#include "rpi3/gpio.h"
#include "rpi3/system_timer.h"
#include "rpi3/uart.h"

#include "rpi3/blink.h"

void blink_once()
{
    // Turn on GPIO 24
    gpio[GPSET0] |= 1 << 24;

    timer_delay_ms(500);

    // Turn off GPIO 24
    gpio[GPCLR0] |= 1 << 24;

    timer_delay_ms(500);
}

void blink_code(uint32_t err)
{
    for(int i = 0; i < err; ++i)
    {
        blink_once();
    }

    // Only delay 4 seconds, since we delay for 1 additional
    // second in blink_once().
    timer_delay_ms(4500);
}

void blink_for(uint32_t duration)
{
    // Turn on GPIO 24
    gpio[GPSET0] |= 1 << 24;

    timer_delay_ms(duration);

    // Turn off GPIO 24
    gpio[GPCLR0] |= 1 << 24;

    timer_delay_ms(duration);
}
