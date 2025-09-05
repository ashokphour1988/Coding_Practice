CC=gcc

all: output

output: overlap.o
	$(CC) -o output overlap.o

overlap.o: overlap.c
	$(CC) -c overlap.c

# --- clean ---
clean:
	rm -f *.o
	rm -f output
