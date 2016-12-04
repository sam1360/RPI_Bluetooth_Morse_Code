#include <string.h>
#include "bt-receive/converter.h"

charMorse convert_to_morse(char c){
    charMorse value;
    switch(c){
        case 'a':
        case 'A':
            value.character = 'a';
            strncpy(value.morse, "*-", MORSE_MAX_LEN + 1);
            break;
        case 'b':
        case 'B':
            value.character = 'b';
            strncpy(value.morse,"-***", MORSE_MAX_LEN + 1);
            break;
        case 'c':
        case 'C':
            value.character = 'c';
            strncpy(value.morse, "-*-*", MORSE_MAX_LEN + 1);
            break;
        case 'd':
        case 'D':
            value.character = 'd';
            strncpy(value.morse, "-**", MORSE_MAX_LEN + 1);
            break;
        case 'e':
        case 'E':
            value.character = 'e';
            strncpy(value.morse, "*", MORSE_MAX_LEN + 1);
            break;
        case 'f':
        case 'F':
            value.character = 'f';
            strncpy(value.morse, "**-*", MORSE_MAX_LEN + 1);
            break;
        case 'g':
        case 'G':
            value.character = 'g';
            strncpy(value.morse, "--*", MORSE_MAX_LEN + 1);
            break;
        case 'h':
        case 'H':
            value.character = 'f';
            strncpy(value.morse, "****", MORSE_MAX_LEN + 1);
            break;
        case 'i':
        case 'I':
            value.character = 'i';
            strncpy(value.morse, "**", MORSE_MAX_LEN + 1);
            break;
        case 'j':
        case 'J':
            value.character = 'j';
            strncpy(value.morse, "*---", MORSE_MAX_LEN + 1);
            break;
        case 'k':
        case 'K':
            value.character = 'k';
            strncpy(value.morse, "-*-", MORSE_MAX_LEN + 1);
            break;
        case 'l':
        case 'L':
            value.character = 'l';
            strncpy(value.morse, "*-**", MORSE_MAX_LEN + 1);
            break;
        case 'm':
        case 'M':
            value.character = 'm';
            strncpy(value.morse, "--", MORSE_MAX_LEN + 1);
            break;
        case 'n':
        case 'N':
            value.character = 'n';
            strncpy(value.morse, "-*", MORSE_MAX_LEN + 1);
            break;
        case 'o':
        case 'O':

            value.character = 'o';
            strncpy(value.morse, "---", MORSE_MAX_LEN + 1);
            break;
        case 'p':
        case 'P':

            value.character = 'p';
            strncpy(value.morse, "*--*", MORSE_MAX_LEN + 1);
            break;
        case 'q':
        case 'Q':

            value.character = 'q';
            strncpy(value.morse, "--*-", MORSE_MAX_LEN + 1);
            break;
        case 'r':
        case 'R':
            value.character = 'r';
            strncpy(value.morse, "*-*", MORSE_MAX_LEN + 1);
            break;

        case 's':
        case 'S':
            value.character = 's';
            strncpy(value.morse, "***", MORSE_MAX_LEN + 1);
            break;

        case 't':
        case 'T':
            value.character = 't';
            strncpy(value.morse, "-", MORSE_MAX_LEN + 1);
            break;

        case 'u':
        case 'U':
            value.character = 'u';
            strncpy(value.morse, "**-", MORSE_MAX_LEN + 1);
            break;

        case 'v':
        case 'V':
            value.character = 'v';
            strncpy(value.morse, "***-", MORSE_MAX_LEN + 1);
            break;

        case 'w':
        case 'W':
            value.character = 'w';
            strncpy(value.morse, "*--", MORSE_MAX_LEN + 1);
            break;

        case 'x':
        case 'X':
            value.character = 'x';
            strncpy(value.morse, "-**-", MORSE_MAX_LEN + 1);
            break;

        case 'y':
        case 'Y':
            value.character = 'y';
            strncpy(value.morse, "-*--", MORSE_MAX_LEN + 1);
            break;

        case 'z':
        case 'Z':
            value.character = 'z';
            strncpy(value.morse, "--**", MORSE_MAX_LEN + 1);
            break;
        case '1':
            value.character = '1';
            strncpy(value.morse, "*----", MORSE_MAX_LEN + 1);
            break;
        case '2':
            value.character = '2';
            strncpy(value.morse, "**---", MORSE_MAX_LEN + 1);
            break;
        case '3':
            value.character = '3';
            strncpy(value.morse, "***--", MORSE_MAX_LEN + 1);
            break;
        case '4':
            value.character = '4';
            strncpy(value.morse, "****-", MORSE_MAX_LEN + 1);
            break;
        case '5':
            value.character = '5';
            strncpy(value.morse, "*****", MORSE_MAX_LEN + 1);
            break;
        case '6':
            value.character = '6';
            strncpy(value.morse, "-****", MORSE_MAX_LEN + 1);
            break;
        case '7':
            value.character = '7';
            strncpy(value.morse, "--***", MORSE_MAX_LEN + 1);
            break;
        case '8':
            value.character = '8';
            strncpy(value.morse, "---**", MORSE_MAX_LEN + 1);
            break;
        case '9':
            value.character = '9';
            strncpy(value.morse, "----*", MORSE_MAX_LEN + 1);
            break;
        case '0':
            value.character = '0';
            strncpy(value.morse, "-----", MORSE_MAX_LEN + 1);
            break;
        default:
            value.character = ' ';
            strncpy(value.morse, "", MORSE_MAX_LEN + 1);
            break;
    }

    return value;
}

