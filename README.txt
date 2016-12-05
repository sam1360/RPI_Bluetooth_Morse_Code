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
install the required Bluetooth libraries with the following command:

                 sudo apt-get install bluez libbluetooth-dev

Also ensure that Raspbian libraries are updated with

                              sudo apt-get update

In order to utilize GPIO functionality on the Raspberry Pi, the wiringPi
library is used. WiringPi is not available on apt-get, but can be acquired
using `git` and the following commands:

                   git clone git://git.drogon.net/wiringPi
                                 cd wiringPi
                                   ./build

Before compiling, make sure that `gcc` and `make` are installed. Both of
these programs come with Raspbian out of the box, but the following commands
can be used to verify that they are still there:

                                gcc --version
                                make --version

Once the presence of `gcc` and `make` are verified, the following command will
compile both `send` and `receive` into the bin/ directory:

                                     make

If you want to connect to a receiving Raspberry Pi using a different device
that has access to the BlueZ library, you can compile the `send` program
individually using the following command:

                                  make send

The device will then be able to send to the Raspberry Pi by running `send`.


Hardware Set-up ======================================================= [HSE02]


The electronic Morse code pulses are sent through GPIO pin 17, so to use an
LED with the program, connect a grounded LED to GPIO pin 17 with a jumper
cable.

It is possible to use the UART with the program.


Execution ============================================================= [EXE03]

Before executing this program, be sure to specify the Bluetooth connection to
drive through the Mini-UART in Raspbian's config.txt. Also make sure to set
the core frequency to 250. The following options in config.txt will accomplish
this:

                           dtoverlay=pi-miniuart-bt
                                core_freq=250

This program is split into two parts: `send` and `receive`. `send` allows the
user to connect to a Raspberry Pi running `receive` with a specified bluetooth
address, like so:

                             send A1:B2:C3:D4:E5

Before executing the `receive` portion of the program, run `bluetoothctl` and
enter the following commands in the console:

                               discoverable on
                                     exit

This allows the computer or Pi running the `send` program to establish the
connection. Then, run `receive` with the following command:

                                 sudo receive

Then, any program running `send` can send messages to the receiving Pi, which
will convert the messages to Morse code in the form of electronic impulses.


==============================================================================
