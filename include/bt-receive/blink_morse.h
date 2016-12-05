#ifndef RPI_BLUETOOTH_MORSE_CODE_BLINK_MORSE_H
#define RPI_BLUETOOTH_MORSE_CODE_BLINK_MORSE_H

// Defines the length of a unit of time for the Morse code, in milliseconds.
#define TICK 500

/**
 * Use the buffer to blink Morse code.
 * The buffer is converted to a table using the provided codes. In
 * international Morse code, a dot is 1 time unit on, a dash is 3 time units on,
 * the space between mid-letter dots and dashes is 1 time unit off, the space
 * between letters is 3 time units off, and the space between words is 7 time
 * units off.
 *
 * @param buffer The buffer used for creating the Morse code signal.
 * @param codes  The table of Morse codes to derive conversions from.
 */
void blink_signal_from_input( const char * buffer, Morse * codes );

#endif // RPI_BLUETOOTH_MORSE_CODE_BLINK_MORSE_H
