#include <string.h>
#include "bt-receive/converter.h"

void test_converter(void) {
    const char * buffer = "Morse Code";
    size_t size = strlen(buffer);
    Morse * codes = build_code_table();
    Morse * converted = get_codes_from_input( buffer, size, codes );
    destroy_converted_table( converted, size );
    destroy_code_table( codes );
}
