CC = gcc
CFLAGS = -I.. -Wall -Wextra -pedantic

all: tag_decoder_encoder

tag_decoder_encoder: *.o
	$(CC) $^ $(CFLAGS) -o $@

%.o: ../%.c %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o tag_decoder_encoder
