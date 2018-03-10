CFLAGS = -Wall -Wextra -pedantic

all: main

main: osct_encoder.o main.o
	gcc $^ $(CFLAGS) -o $@

encoder.o: osct_encoder.c
	gcc -c $^ $(CFLAGS)

main.o: main.c
	gcc -c $^ $(CFLAGS)

clean:
	rm *.o main
