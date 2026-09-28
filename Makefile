CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SINGLE_FILES = bidding.c set-1-main.c set-3-main.c set-4-main.c set-5-main.c

all: bidding set-1 set-3 set-4 set-5 set-6

bidding: bidding.c
	$(CC) $(CFLAGS) -o $@ bidding.c

set-1: set-1-main.c
	$(CC) $(CFLAGS) -o $@ set-1-main.c

set-3: set-3-main.c
	$(CC) $(CFLAGS) -o $@ set-3-main.c

set-4: set-4-main.c
	$(CC) $(CFLAGS) -o $@ set-4-main.c

set-5: set-5-main.c
	$(CC) $(CFLAGS) -o $@ set-5-main.c

set-6: set-6-main.c set-6-op.c set-6.h
	$(CC) $(CFLAGS) -o $@ set-6-main.c set-6-op.c -lm

clean:
	rm -f bidding set-1 set-3 set-4 set-5 set-6

.PHONY: all clean
