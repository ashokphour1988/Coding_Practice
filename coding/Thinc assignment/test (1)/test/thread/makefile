CC=gcc

all: output

output: thread.o
	$(CC) -o output thread.o -lpthread

thread.o: thread.c
	$(CC) -c thread.c

# --- clean ---
clean:
	rm -f *.o
	rm -f output
