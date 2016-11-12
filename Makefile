CC = gcc

SRCDIR = source/
INCLUDEDIR = include/
TARGETPATH = bin/

RECEIVE = bt-receive/
SEND = bt-send/


CFLAGS = -ggdb -Wall -Wextra -pedantic -Werror -O2 -I $(INCLUDEDIR)

all: receive send


receive:
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)bt-receive.c -o $(TARGETPATH)receive


send:
	$(CC) $(CFLAGS) $(SRCDIR)$(SEND)bt-send.c -o $(TARGETPATH)send


.PHONY: clean

clean:
	-rm -f $(TARGETPATH)*
