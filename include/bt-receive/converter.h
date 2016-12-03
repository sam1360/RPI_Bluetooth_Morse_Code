#ifndef RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H
#define RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H

#include "bt-receive/morse_char.h"

/**
 * Converts a character input to Morse code format.
 *
 * @param c  The character to convert.
 * @return   The converted character.
 */
static charMorse convert_to_morse( char c );

#endif // RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H