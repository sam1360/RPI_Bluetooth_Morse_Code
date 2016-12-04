#ifndef RPI3_BLINK_H_
#define RPI3_BLINK_H_

#include "rpi3/gpio.h"
#include "rpi3/system_timer.h"
#include "rpi3/uart.h"

void blink_once();

void blink_code(uint32_t err);

void blink_for(uint32_t duration);

#endif // RPI3_BLINK_H_
