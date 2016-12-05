#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <wiringPi.h>

#include "bt-receive/converter.h"
#include "bt-receive/blink_morse.h"

int main(void)
{
    struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
    char buf[1024] = { 0 };
    int s, client, bytes_read;
    socklen_t opt = sizeof(rem_addr);

    // create morse code table
    Morse * codes = build_code_table();

    // prepare wiringPi pin 0 ( GPIO 17 )
    wiringPiSetup();
    pinMode( 0, OUTPUT );

    // allocate socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // bind socket to port 1 of the first available
    // local bluetooth adapter
    loc_addr.rc_family = AF_BLUETOOTH;
    loc_addr.rc_bdaddr = *BDADDR_ANY;
    loc_addr.rc_channel = (uint8_t) 1;
    bind(s, (struct sockaddr *)&loc_addr, sizeof(loc_addr));

    // put socket into listening mode
    listen(s, 1);

    // accept one connection
    client = accept(s, (struct sockaddr *)&rem_addr, &opt);

    ba2str( &rem_addr.rc_bdaddr, buf );
    fprintf(stderr, "Accepted connection from %s\n", buf);

    while(1) {
        memset(buf, 0, sizeof(buf)); // clear buffer for input

        // read data from the client
        bytes_read = read(client, buf, sizeof(buf));
        if( bytes_read > 0 ) {
            printf("Received [%s]\n", buf);
            printf("Morse code translation:\n");
            blink_signal_from_input( buf, codes );
        }
    }

    // close connection
    close(client);
    close(s);
    destroy_code_table( codes );
    return 0;
}
