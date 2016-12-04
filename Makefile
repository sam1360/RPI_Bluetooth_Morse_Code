CC = gcc

SRCDIR = source/
INCLUDEDIR = include/
TARGETPATH = bin/
OBJDIR = obj/

RECEIVE = bt-receive/
SEND = bt-send/
TEST = test/


CFLAGS = -std=c99 -ggdb -Wall -Wextra -pedantic -Werror -O2 -I $(INCLUDEDIR)

all: receive send tests


receive: converter
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)bt-receive.c $(OBJDIR)converter.o -o $(TARGETPATH)receive -lbluetooth

converter:
	$(CC) $(CFLAGS) $(SRCDIR)$(RECEIVE)converter.c -c -o $(OBJDIR)converter.o


send:
	$(CC) $(CFLAGS) $(SRCDIR)$(SEND)bt-send.c -o $(TARGETPATH)send -lbluetooth

tests: test_converter
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)tests.c $(OBJDIR)test_converter.o $(OBJDIR)converter.o -o $(TARGETPATH)tests

test_converter: converter
	$(CC) $(CFLAGS) $(SRCDIR)$(TEST)test_converter.c -c -o $(OBJDIR)test_converter.o

.PHONY: clean

clean:
	-rm -f $(TARGETPATH)*
