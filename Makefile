CC = gcc

SRCDIR = source/
INCLUDEDIR = include/
TARGETPATH = bin/
OBJDIR = obj/

RECEIVE = bt-receive/
SEND = bt-send/
RPI = rpi3/
TEST = test/


CFLAGS = -std=c99 -ggdb -Wall -Wextra -pedantic -Werror -O2 -I $(INCLUDEDIR)

all: receive send tests


receive: converter blink_morse
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)bt-receive.c $(OBJDIR)converter.o $(OBJDIR)blink_morse.o $(OBJDIR)blink.o -o $(TARGETPATH)receive -lbluetooth -lwiringPi

blink_morse: converter blink
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)blink_morse.c -c -o $(OBJDIR)blink_morse.o -lwiringPi

converter:
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)converter.c -c -o $(OBJDIR)converter.o

blink:
	$(CC) $(CFLAGS) $(SRCDIR)$(RPI)blink.c -c -o $(OBJDIR)blink.o -lwiringPi


send:
	$(CC) $(CFLAGS) $(SRCDIR)$(SEND)bt-send.c -o $(TARGETPATH)send -lbluetooth

tests: test_converter test_blink test_blink_morse
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)tests.c $(OBJDIR)test_converter.o $(OBJDIR)converter.o $(OBJDIR)test_blink.o $(OBJDIR)blink.o $(OBJDIR)test_blink_morse.o $(OBJDIR)blink_morse.o -o $(TARGETPATH)tests -lwiringPi

test_converter: converter
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)test_converter.c -c -o $(OBJDIR)test_converter.o

test_blink: blink
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)test_blink.c -c -o $(OBJDIR)test_blink.o -lwiringPi

test_blink_morse: blink_morse
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)test_blink_morse.c -c -o $(OBJDIR)test_blink_morse.o -lwiringPi



.PHONY: clean

clean:
	-rm -f $(TARGETPATH)*
	-rm -f $(OBJDIR)*
