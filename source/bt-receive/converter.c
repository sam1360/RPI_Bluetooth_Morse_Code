#include <string.h>
#include <stdlib.h>
#include "bt-receive/converter.h"

static void char_to_morse( Morse value, const char c, const char * convStr, uint32_t code ) {
    value->character = c;
    value->code = code;
    strncpy( value->convStr, convStr, MORSE_MAX_LEN + 1 );
}

Morse convert_to_morse(char c) {
    Morse value = malloc( sizeof(struct morseStruct) );
    switch(c){
        case 'a':
        case 'A':
            char_to_morse( value, 'a', "*-", 0x17 ); //10111
            break;

        case 'b':
        case 'B':
            char_to_morse( value, 'b', "-***", 0x1D5 ); // 111010101
            break;

        case 'c':
        case 'C':
            char_to_morse( value, 'c', "-*-*", 0x75D ); // 11101011101
            break;

        case 'd':
        case 'D':
            char_to_morse( value, 'd', "-**", 0x75 ); // 1110101
            break;

        case 'e':
        case 'E':
            char_to_morse( value, 'e', "*", 0x1 ); // 1
            break;

        case 'f':
        case 'F':
            char_to_morse( value, 'f', "**-*", 0x15D ); // 101011101
            break;

        case 'g':
        case 'G':
            char_to_morse( value, 'g', "--*", 0x1DD ); // 111011101
            break;

        case 'h':
        case 'H':
            char_to_morse( value, 'f', "****", 0x55 ); // 1010101
            break;

        case 'i':
        case 'I':
            char_to_morse( value, 'i', "**", 0x5 ); // 101
            break;

        case 'j':
        case 'J':
            char_to_morse( value, 'j', "*---", 0x1777 ); // 1011101110111
            break;

        case 'k':
        case 'K':
            char_to_morse( value, 'k', "-*-", 0x1D7); // 111010111
            break;

        case 'l':
        case 'L':
            char_to_morse( value, 'l', "*-**", 0x175 ); // 101110101
            break;

        case 'm':
        case 'M':
            char_to_morse( value, 'm', "--", 0x77 ); // 1110111
            break;

        case 'n':
        case 'N':
            char_to_morse( value, 'n', "-*", 0x1D ); // 11101
            break;

        case 'o':
        case 'O':
            char_to_morse( value, 'o', "---", 0x777 ); // 11101110111
            break;

        case 'p':
        case 'P':
            char_to_morse( value, 'p', "*--*", 0x5DD ); // 10111011101
            break;

        case 'q':
        case 'Q':
            char_to_morse( value, 'q', "--*-", 0x1DD7 ); // 1110111010111
            break;

        case 'r':
        case 'R':
            char_to_morse( value, 'r', "*-*", 0x5D ); // 1011101
            break;

        case 's':
        case 'S':
            char_to_morse( value, 's', "***", 0x15 ); // 10101
            break;

        case 't':
        case 'T':
            char_to_morse( value, 't', "-", 0x7 ); // 111
            break;

        case 'u':
        case 'U':
            char_to_morse( value, 'u', "**-", 0x57 ); // 1010111
            break;

        case 'v':
        case 'V':
            char_to_morse( value, 'v', "***-", 0x157 ); // 101010111
            break;

        case 'w':
        case 'W':
            char_to_morse( value, 'w', "*--", 0x177 ); // 101110111
            break;

        case 'x':
        case 'X':
            char_to_morse( value, 'x', "-**-", 0x757 ); // 11101010111
            break;

        case 'y':
        case 'Y':
            char_to_morse( value, 'y', "-*--", 0x1D77 ); // 1110101110111
            break;

        case 'z':
        case 'Z':
            char_to_morse( value, 'z', "--**", 0x775 ); // 11101110101
            break;

        case '1':
            char_to_morse( value, '1', "*----", 0x17777 ); // 10111011101110111
            break;

        case '2':
            char_to_morse( value, '2', "**---", 0x5777 ); // 101011101110111
            break;

        case '3':
            char_to_morse( value, '3', "***--", 0x1577 ); // 1010101110111
            break;

        case '4':
            char_to_morse( value, '4', "****-", 0x557 ); // 10101010111
            break;

        case '5':
            char_to_morse( value, '5', "*****", 0x155 ); // 101010101
            break;

        case '6':
            char_to_morse( value, '6', "-****", 0x755 ); // 11101010101
            break;

        case '7':
            char_to_morse( value, '7', "--***", 0x1DD5 ); // 1110111010101
            break;

        case '8':
            char_to_morse( value, '8', "---**", 0x7775 ); // 111011101110101
            break;

        case '9':
            char_to_morse( value, '9', "----*", 0x1DDDD ); // 11101110111011101
            break;

        case '0':
            char_to_morse( value, '0', "-----", 0x77777 ); // 1110111011101110111
            break;

        default:
            char_to_morse( value, ' ', "", 0x0 );
            break;
    }

    return value;
}

