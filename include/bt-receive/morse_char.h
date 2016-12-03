//
// Created by Sam on 12/3/2016.
//

#ifndef RPI_BLUETOOTH_MORSE_CODE_MORSE_CHAR_H
#define RPI_BLUETOOTH_MORSE_CODE_MORSE_CHAR_H

// No Morse characters with greater than 5 components exist
#define MORSE_MAX_LEN 5

typedef struct {
    char character;
    char morse[MORSE_MAX_LEN + 1];
} charMorse;
#endif //RPI_BLUETOOTH_MORSE_CODE_MORSE_CHAR_H

