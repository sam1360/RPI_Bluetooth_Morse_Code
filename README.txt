rpi-morse
------------------------------------------------------------------------------
                           _
                _ __ _ __ (_)      _ __ ___   ___  _ __ ___  ___
               | '__| '_ \| |_____| '_ ` _ \ / _ \| '__/ __|/ _ \
               | |  | |_) | |_____| | | | | | (_) | |  \__ \  __/
               |_|  | .__/|_|     |_| |_| |_|\___/|_|  |___/\___|
                    |_|

Uses the Raspberry Pi 3's Bluetooth module to transfer and convert messages
into Morse code.


Group Members ================================================================


Brian Alexander Mejorado
Samuel Mosher


Table of Contents ==================================================== [TOC00]


1. Compilation [COM01]
2. Hardware Set-up [HSE02]
3. Execution [EXE03]


Compilation =========================================================== [COM01]


This application executes using two separate programs: send and receive.
Before compiling the code, both the receiving and sending Raspberry Pi 3 must
install the required libraries with the following command:

                 sudo apt-get install bluez libbluetooth-dev

Also ensure that Raspbian libraries are updated with

                              sudo apt-get update

Before compiling, also make sure that `gcc` and `make` are installed. Both of
these programs come with Raspbian out of the box, but the following commands
can be used to verify this:

                                gcc --version
                                make --version

Once the presence of `gcc` and `make` are verified, the following command will
compile both `send` and `receive` into the bin/ directory:

                                     make


Hardware Set-up ======================================================= [HSE02]


TODO Write This


Execution ============================================================= [EXE03]


TODO Write This


==============================================================================
