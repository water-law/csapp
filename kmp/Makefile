CFLAGS = -g
	
CC = gcc

PROG = kmp kmp1

all: $(PROG)

kmp: kmp.c
	$(CC) $(CFLAGS) -o kmp kmp.c
	
kmp1: kmp1.c
	$(CC) $(CFLAGS) -o kmp1 kmp1.c
	
clean:
	rm -f *.o $(PROG)