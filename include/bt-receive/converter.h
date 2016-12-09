#ifndef RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H
#define RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H

#include "bt-receive/morse.h"

/**
 * Builds the set of Morse codes supported by the system.
 *
 * @return  The created table.
 */
Morse * build_code_table(void);

/**
 * Converts the input buffer into a table of converted Morse code values.
 * This function returns a table of *references* to Morse codes in the already
 * existing code table. Through this, we reduce a lot of the requisite memory
 * and time complexity overhead.
 *
 * @param buffer  The input buffer to convert.
 * @param size    The size of the input buffer.
 * @param codes   The table of static code values to use.
 * @return        A list of codes corresponding to the buffer.
 */
Morse * get_codes_from_input( const char * buffer, size_t size, Morse * codes );

/**
 * Destroys the code table.
 * Call this before closing the application.
 *
 * @pre codes != 0
 */
void destroy_code_table( Morse * codes );

/**
 * Destroys the conversion table.
 * Call this after you're done with handling a single call of user input.
 *
 * @pre converted != 0
 * @param size  The size of the converted table; the same size as the user input.
 */
void destroy_converted_table( Morse * converted, size_t size );

#endif // RPI_BLUETOOTH_MORSE_CODE_CONVERTER_H
