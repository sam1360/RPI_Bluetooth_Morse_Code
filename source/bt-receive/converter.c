#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "bt-receive/converter.h"

static Morse build_morse(  const char c, const char * convStr, uint32_t code ) {
    Morse value = malloc( sizeof(struct morseStruct) );
    if( value == NULL ) {
        fprintf(stderr, "Could not allocate enough space to build the table!\n" );
        exit(-1);
    }
    value->character = c;
    value->code = code;
    strncpy( value->convStr, convStr, MORSE_MAX_LEN + 1 );
    return value;
}

Morse * build_code_table(void) {
    Morse * codes = malloc( sizeof(Morse *) * NUM_CODES );
    if( codes == NULL ) {
        fprintf(stderr, "Could not allocate enough space to build the table!\n" );
        exit(-1);
    }

    // dot = * = 1
    // dash = - = 111
    codes[0]  = build_morse( 'a', "*-", 0x17 ); //10111
    codes[1]  = build_morse( 'b', "-***", 0x1D5 ); // 111010101
    codes[2]  = build_morse( 'c', "-*-*", 0x75D ); // 11101011101
    codes[3]  = build_morse( 'd', "-**", 0x75 ); // 1110101
    codes[4]  = build_morse( 'e', "*", 0x1 ); // 1
    codes[5]  = build_morse( 'f', "**-*", 0x15D ); // 101011101
    codes[6]  = build_morse( 'g', "--*", 0x1DD ); // 111011101
    codes[7]  = build_morse( 'h', "****", 0x55 ); // 1010101
    codes[8]  = build_morse( 'i', "**", 0x5 ); // 101
    codes[9]  = build_morse( 'j', "*---", 0x1777 ); // 1011101110111
    codes[10] = build_morse( 'k', "-*-", 0x1D7); // 111010111
    codes[11] = build_morse( 'l', "*-**", 0x175 ); // 101110101
    codes[12] = build_morse( 'm', "--", 0x77 ); // 1110111
    codes[13] = build_morse( 'n', "-*", 0x1D ); // 11101
    codes[14] = build_morse( 'o', "---", 0x777 ); // 11101110111
    codes[15] = build_morse( 'p', "*--*", 0x5DD ); // 10111011101
    codes[16] = build_morse( 'q', "--*-", 0x1DD7 ); // 1110111010111
    codes[17] = build_morse( 'r', "*-*", 0x5D ); // 1011101
    codes[18] = build_morse( 's', "***", 0x15 ); // 10101
    codes[19] = build_morse( 't', "-", 0x7 ); // 111
    codes[20] = build_morse( 'u', "**-", 0x57 ); // 1010111
    codes[21] = build_morse( 'v', "***-", 0x157 ); // 101010111
    codes[22] = build_morse( 'w', "*--", 0x177 ); // 101110111
    codes[23] = build_morse( 'x', "-**-", 0x757 ); // 11101010111
    codes[24] = build_morse( 'y', "-*--", 0x1D77 ); // 1110101110111
    codes[25] = build_morse( 'z', "--**", 0x775 ); // 11101110101
    codes[26] = build_morse( '0', "-----", 0x77777 ); // 1110111011101110111
    codes[27] = build_morse( '1', "*----", 0x17777 ); // 10111011101110111
    codes[28] = build_morse( '2', "**---", 0x5777 ); // 101011101110111
    codes[29] = build_morse( '3', "***--", 0x1577 ); // 1010101110111
    codes[30] = build_morse( '4', "****-", 0x557 ); // 10101010111
    codes[31] = build_morse( '5', "*****", 0x155 ); // 101010101
    codes[32] = build_morse( '6', "-****", 0x755 ); // 11101010101
    codes[33] = build_morse( '7', "--***", 0x1DD5 ); // 1110111010101
    codes[34] = build_morse( '8', "---**", 0x7775 ); // 111011101110101
    codes[35] = build_morse( '9', "----*", 0x1DDDD ); // 11101110111011101
    codes[36] = build_morse( ' ', " ", 0x0 );

    return codes;
}

static size_t get_code_index( char c ) {
    size_t result = 36;
    if( 'a' <= c && 'z' >= c ) { // 'a' <= c <= 'z'
        result = c - 'a';
    }
    else if( 'A' <= c && 'Z' >= c ) { // 'A' <= c <= 'Z'
        result = c - 'A';
    }
    else if( '0' <= c && '9' >= c ) { // '0' <= c <= '9'
        result = c - '0' + 26;
    }
    return result;
}

Morse * get_codes_from_input( const char * buffer, size_t size, Morse * codes ) {
    Morse * converted = malloc( sizeof(Morse) * size );
    if( converted == NULL ) {
        fprintf( stderr, "Could not allocate enough space to build the table!\n" );
        exit(-1);
    }
    for( size_t i = 0; i < size; i++ ) { // index into the code table
        converted[i] = codes[ get_code_index(buffer[i]) ];
        printf( "%s ", converted[i]->convStr );
    }
    printf( "\n" );
    return converted;
}

void destroy_code_table( Morse * codes ) {
    if( codes == NULL ) {
        return;
    }
    for( size_t i = 0; i < NUM_CODES; i++ ) {
        if( codes[i] != 0 ) {
            free( codes[i] );
            codes[i] = 0;
        }
    }
    free( codes );
}

void destroy_converted_table( Morse * converted, size_t size ) {
    if( converted == NULL ) {
        return;
    }
    for( size_t i = 0; i < size; i++ ) {
        converted[i] = 0;
    }
    free( converted );
}
