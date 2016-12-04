//
// Created by Sam on 12/3/2016.
//

#ifndef RPI_BLUETOOTH_MORSE_CODE_MORSE_H
#define RPI_BLUETOOTH_MORSE_CODE_MORSE_H


#include <stdint.h>

// No Morse characters with greater than 5 components exist
#define MORSE_MAX_LEN 5

struct morseStruct {
    char character;
    char convStr[MORSE_MAX_LEN + 1];
    uint32_t code;
};

typedef struct morseStruct * Morse;

#endif //RPI_BLUETOOTH_MORSE_CODE_MORSE_H

