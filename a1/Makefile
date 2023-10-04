CC=g++
CFLAGS=-I
DEPS=scanner.hpp

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

scanner: scanner.o
	$(CC) -o scanner scanner.o

clean:
	rm *.o scanner
