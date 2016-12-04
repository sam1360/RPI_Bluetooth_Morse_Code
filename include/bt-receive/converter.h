#ifndef RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H
#define RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H

#include "bt-receive/morse.h"

/**
 * Acquire the index of the code in the table corresponding to the character.
 *
 * @param c  The character to convert.
 * @return   The converted character.
 */
size_t get_code_index( char c );

/**
 * Builds the set of Morse codes supported by the system.
 */
Morse * build_code_table(void);

#endif // RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H
