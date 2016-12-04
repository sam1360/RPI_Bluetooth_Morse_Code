#include <string.h>
#include <stdlib.h>
#include "bt-receive/converter.h"

static void char_to_morse( Morse value, const char c, const char * convStr ) {
    value->character = c;
    strncpy( value->convStr, convStr, MORSE_MAX_LEN + 1 );
}

Morse convert_to_morse(char c) {
    Morse value = malloc( sizeof(struct morseStruct) );
    switch(c){
        case 'a':
        case 'A':
            char_to_morse( value, 'a', "*-" );
            break;

        case 'b':
        case 'B':
            char_to_morse( value, 'b', "-***" );
            break;

        case 'c':
        case 'C':
            char_to_morse( value, 'c', "-*-*" );
            break;

        case 'd':
        case 'D':
            char_to_morse( value, 'd', "-**" );
            break;

        case 'e':
        case 'E':
            char_to_morse( value, 'e', "*" );
            break;

        case 'f':
        case 'F':
            char_to_morse( value, 'f', "**-*" );
            break;

        case 'g':
        case 'G':
            char_to_morse( value, 'g', "--*" );
            break;

        case 'h':
        case 'H':
            char_to_morse( value, 'f', "****" );
            break;

        case 'i':
        case 'I':
            char_to_morse( value, 'i', "**" );
            break;

        case 'j':
        case 'J':
            char_to_morse( value, 'j', "*---" );
            break;

        case 'k':
        case 'K':
            char_to_morse( value, 'k', "-*-" );
            break;

        case 'l':
        case 'L':
            char_to_morse( value, 'l', "*-**" );
            break;

        case 'm':
        case 'M':
            char_to_morse( value, 'm', "--" );
            break;

        case 'n':
        case 'N':
            char_to_morse( value, 'n', "-*" );
            break;

        case 'o':
        case 'O':
            char_to_morse( value, 'o', "---" );
            break;

        case 'p':
        case 'P':
            char_to_morse( value, 'p', "*--*" );
            break;

        case 'q':
        case 'Q':
            char_to_morse( value, 'q', "--*-" );
            break;

        case 'r':
        case 'R':
            char_to_morse( value, 'r', "*-*" );
            break;

        case 's':
        case 'S':
            char_to_morse( value, 's', "***" );
            break;

        case 't':
        case 'T':
            char_to_morse( value, 't', "-" );
            break;

        case 'u':
        case 'U':
            char_to_morse( value, 'u', "**-" );
            break;

        case 'v':
        case 'V':
            char_to_morse( value, 'v', "***-" );
            break;

        case 'w':
        case 'W':
            char_to_morse( value, 'w', "*--" );
            break;

        case 'x':
        case 'X':
            char_to_morse( value, 'x', "-**-" );
            break;

        case 'y':
        case 'Y':
            char_to_morse( value, 'y', "-*--" );
            break;

        case 'z':
        case 'Z':
            char_to_morse( value, 'z', "--**" );
            break;

        case '1':
            char_to_morse( value, '1', "*----" );
            break;

        case '2':
            char_to_morse( value, '2', "**---" );
            break;

        case '3':
            char_to_morse( value, '3', "***--" );
            break;

        case '4':
            char_to_morse( value, '4', "****-" );
            break;

        case '5':
            char_to_morse( value, '5', "*****" );
            break;

        case '6':
            char_to_morse( value, '6', "-****" );
            break;

        case '7':
            char_to_morse( value, '7', "--***" );
            break;

        case '8':
            char_to_morse( value, '8', "---**" );
            break;

        case '9':
            char_to_morse( value, '9', "----*" );
            break;

        case '0':
            char_to_morse( value, '0', "-----" );
            break;

        default:
            char_to_morse( value, ' ', "" );
            break;
    }

    return value;
}

