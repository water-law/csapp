CFLAGS = -g
	
CC = gcc

PROG = main_base mask newmain reverse_array show_bytes start

all: $(PROG)

main_base: main_base.c
	$(CC) $(CFLAGS) -o main_base main_base.c
	
mask: mask.c
	$(CC) $(CFLAGS) -o mask mask.c

newmain: newmain.c
	$(CC) $(CFLAGS) -o newmain newmain.c


reverse_array: reverse_array.c
	$(CC) $(CFLAGS) -o reverse_array reverse_array.c


show_bytes: show_bytes.c
	$(CC) $(CFLAGS) -o show_bytes show_bytes.c


start: start.c
	$(CC) $(CFLAGS) -o start start.c

clean:
	rm -f *.o *.exe $(PROG)