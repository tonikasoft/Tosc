CC = gcc
CFLAGS = -I.. -Wall -Wextra -pedantic

all: main

main: *.o
	$(CC) $^ $(CFLAGS) -o $@

%.o: ../%.c %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o main
