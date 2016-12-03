#include <stddef.h>
#include <stdint.h>

#include "rpi3/debug.h"

uint32_t idiv(const uint32_t numerator, const uint32_t denominator)
{
    // Get rid of the impossible case
    if( y == 0 ) {
        return 0;
    }

    uint32_t a, b, c, result, count;
    result = 0;
    c = x;

    // Use long division (same concept in binary as in decimal)
    while( c >= y ) {
        a = c >> 1;        // Shift over to next value
        b = y;
        count = 1;
        while( a >= b ) {  // "Drop down" values from the numerator
            b <<= 1;
            count <<= 1;
        }
        c -= b;
        result += count;   // Add by the relative amount of loops
    }
    return result;
}

uint32_t imod(const uint32_t x, const uint32_t n)
{
    return ( x - (idiv(x, n) * n) );
}

char digit_to_char(char ch)
{
    if (ch < 10)
    {
        return ch + '0';
    }
    else
    {
        return (ch % 10) + 'A';
    }
}

char* convert(uint32_t base, uint32_t numToConvert, char* buffer)
{
    if (numToConvert == 0)
    {
        buffer[0] = '0';
        buffer[1] = '\0';
    }
    else
    {
        size_t i = 0;
        while(numToConvert != 0)
        {
            buffer[i++] = digit_to_char(imod(numToConvert, base));
            numToConvert = idiv(numToConvert, base);
        }
        char *start = buffer;
        char *end = start + i - 1;
        char temp;
        while (end > start)
        {
            temp = *start;
            *start = *end;
            *end = temp;

            ++start;
            --end;
        }
        buffer[i] = '\0';
    }

    return buffer;
}

char* to_binary_str(uint32_t numToConvert, char* buffer)
{
    return convert(2, numToConvert, buffer);
}

char* to_hex_str(uint32_t numToConvert, char* buffer)
{
    return convert(16, numToConvert, buffer);
}

char* to_decimal_str(uint32_t numToConvert, char* buffer)
{
    return convert(10, numToConvert, buffer);
}
