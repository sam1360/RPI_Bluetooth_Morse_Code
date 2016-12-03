CC = gcc

SRCDIR = source/
INCLUDEDIR = include/
TARGETPATH = bin/
OBJDIR = obj/

RECEIVE = bt-receive/
SEND = bt-send/


CFLAGS = -ggdb -Wall -Wextra -pedantic -Werror -O2 -I $(INCLUDEDIR)

all: receive send


receive: converter
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)bt-receive.c $(OBJDIR)converter.o -o $(TARGETPATH)receive

converter:
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)converter.c -c -o $(OBJDIR)converter.o


send:
	$(CC) $(CFLAGS) $(SRCDIR)$(SEND)bt-send.c -o $(TARGETPATH)send


.PHONY: clean

clean:
	-rm -f $(TARGETPATH)*
