#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define MAX_SIZE  500

int main( int argc, char * argv[] )
{
    const char * usage = "usage: send bt-receive-addr";
    char buffer[MAX_SIZE];

    if( argc != 2  ) {
        fprintf( stderr, "%s\n", usage );
        return EXIT_FAILURE;
    }
    else if( strlen(argv[1]) != 17 ) {
        fprintf( stderr, "Invalid Bluetooth address: %s.\n", argv[1] );
        return EXIT_FAILURE;
    }

    struct sockaddr_rc addr = { 0 };
    int s, status;
    char * dest = argv[1];

    // allocate a socket
    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    // set the connection parameters (who to connect to)
    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );

    // connect to server
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    while(1){
        if( status == 0 ) {
            scanf( "%s", buffer );
            status = write( s, "hello!", MAX_SIZE );
            status = 0;
        }
        if( status < 0 ) { 
            perror("uh oh");
        }

    }
    // send a message


    close(s);
    return EXIT_SUCCESS;
}
