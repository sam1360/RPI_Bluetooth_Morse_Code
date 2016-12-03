#include <mem.h>
#include "bt-receive/converter.h"

charMorse convert_to_morse(char c){
    charMorse value;
    switch(c){
        case 'a':
        case 'A':
            value.character = 'a';
            strncpy(value.morse, "*-", MORSE_MAX_LEN + 1);
        case 'b':
        case 'B':
            value.character = 'b';
            strncpy(value.morse,"-***", MORSE_MAX_LEN + 1);
        case 'c':
        case 'C':
            value.character = 'c';
            strncpy(value.morse, "-*-*", MORSE_MAX_LEN + 1);
        case 'd':
        case 'D':
            value.character = 'd';
            strncpy(value.morse, "-**", MORSE_MAX_LEN + 1);
        case 'e':
        case 'E':
            value.character = 'e';
            strncpy(value.morse, "*", MORSE_MAX_LEN + 1);
        case 'f':
        case 'F':
            value.character = 'f';
            strncpy(value.morse, "**-*", MORSE_MAX_LEN + 1);
        case 'g':
        case 'G':
            value.character = 'g';
            strncpy(value.morse, "--*", MORSE_MAX_LEN + 1);
        case 'h':
        case 'H':
            value.character = 'f';
            strncpy(value.morse, "****", MORSE_MAX_LEN + 1);
        case 'i':
        case 'I':
            value.character = 'i';
            strncpy(value.morse, "**", MORSE_MAX_LEN + 1);
        case 'j':
        case 'J':
            value.character = 'j';
            strncpy(value.morse, "*---", MORSE_MAX_LEN + 1);
        case 'k':
        case 'K':
            value.character = 'k';
            strncpy(value.morse, "-*-", MORSE_MAX_LEN + 1);
        case 'l':
        case 'L':
            value.character = 'l';
            strncpy(value.morse, "*-**", MORSE_MAX_LEN + 1);
        case 'm':
        case 'M':
            value.character = 'm';
            strncpy(value.morse, "--", MORSE_MAX_LEN + 1);
        case 'n':
        case 'N':
            value.character = 'n';
            strncpy(value.morse, "-*", MORSE_MAX_LEN + 1);
        case 'o':
        case 'O':

            value.character = 'o';
            strncpy(value.morse, "---", MORSE_MAX_LEN + 1);
        case 'p':
        case 'P':

            value.character = 'p';
            strncpy(value.morse, "*--*", MORSE_MAX_LEN + 1);
        case 'q':
        case 'Q':

            value.character = 'q';
            strncpy(value.morse, "--*-", MORSE_MAX_LEN + 1);
        case 'r':
        case 'R':
            value.character = 'r';
            strncpy(value.morse, "*-*", MORSE_MAX_LEN + 1);

        case 's':
        case 'S':
            value.character = 's';
            strncpy(value.morse, "***", MORSE_MAX_LEN + 1);

        case 't':
        case 'T':
            value.character = 't';
            strncpy(value.morse, "-", MORSE_MAX_LEN + 1);

        case 'u':
        case 'U':
            value.character = 'u';
            strncpy(value.morse, "**-", MORSE_MAX_LEN + 1);

        case 'v':
        case 'V':
            value.character = 'v';
            strncpy(value.morse, "***-", MORSE_MAX_LEN + 1);

        case 'w':
        case 'W':
            value.character = 'w';
            strncpy(value.morse, "*--", MORSE_MAX_LEN + 1);

        case 'x':
        case 'X':
            value.character = 'x';
            strncpy(value.morse, "-**-", MORSE_MAX_LEN + 1);

        case 'y':
        case 'Y':
            value.character = 'y';
            strncpy(value.morse, "-*--", MORSE_MAX_LEN + 1);

        case 'z':
        case 'Z':
            value.character = 'z';
            strncpy(value.morse, "--**", MORSE_MAX_LEN + 1);
        case '1':
            value.character = '1';
            strncpy(value.morse, "*----", MORSE_MAX_LEN + 1);
        case '2':
            value.character = '2';
            strncpy(value.morse, "**---", MORSE_MAX_LEN + 1);
        case '3':
            value.character = '3';
            strncpy(value.morse, "***--", MORSE_MAX_LEN + 1);
        case '4':
            value.character = '4';
            strncpy(value.morse, "****-", MORSE_MAX_LEN + 1);
        case '5':
            value.character = '5';
            strncpy(value.morse, "*****", MORSE_MAX_LEN + 1);
        case '6':
            value.character = '6';
            strncpy(value.morse, "-****", MORSE_MAX_LEN + 1);
        case '7':
            value.character = '7';
            strncpy(value.morse, "--***", MORSE_MAX_LEN + 1);
        case '8':
            value.character = '8';
            strncpy(value.morse, "---**", MORSE_MAX_LEN + 1);
        case '9':
            value.character = '9';
            strncpy(value.morse, "----*", MORSE_MAX_LEN + 1);
        case '0':
            value.character = '0';
            strncpy(value.morse, "-----", MORSE_MAX_LEN + 1);
        default:
            value.character = ' ';
            strncpy(value.morse, "", MORSE_MAX_LEN + 1);

    }

    return value;
}

