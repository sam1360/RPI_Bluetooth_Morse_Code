#include <string.h>

#include "rpi3/blink.h"
#include "bt-receive/converter.h"
#include "bt-receive/blink_morse.h"

static void blink_based_on_bit( uint32_t code, size_t j ) {
    if( code & (1 << j) ) { // blink on if jth bit is 1
        blink_on();
    }
    else { // blink off if jth bit is 0
        blink_off();
    }
    delay( 1 * TICK ); // always delay one tick
}


void blink_signal_from_input( const char * buffer, Morse * codes ) {

    /*
     * codes := build_code_table()
     * n := strlen(buffer)
     * converted := get_codes_from_input(buffer, n, codes)
     * for i := 0 to n do
     *    count := 0
     *    if converted[i]->code = 0 then
     *        delay 4 ticks
     *        continue
     *    while converted[i]->code >> count != 1 do
     *        count++
     *    for j := count to 0 do
     *        if ( converted[i]->code & (1 << j) ) = 1 then // if count bit is 1
     *            blink_on()
     *            delay 1 tick
     *        else
     *            blink_off()
     *            delay 1 tick
     *     blink_off()
     *     delay 3 ticks
     */

    size_t n = strlen(buffer);
    Morse * converted = get_codes_from_input( buffer, n, codes );
    for( size_t i = 0; i < n; i++ ) {
        size_t count = 0;
        if( converted[i]->code == 0 ) { // spaces or unsupported chars
            delay( 4 * TICK ); // delay seven (3 + 4) ticks at the end of a word
            continue;
        }
        while( ( converted[i]->code >> count ) != 1 ) {
            count++; // spin until we find the most significant 1
        }
        for( size_t j = count; j = 0; j-- ) { // count down to lsb
            blink_based_on_bit( converted[i]->code, j );
        }
        blink_off(); // blink off for 3 ticks at the end of the letter
        delay( 3 * TICK );
    }
    destroy_converted_table( converted, n );
}
