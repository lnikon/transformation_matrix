CC=g++
CFLAGS=-Wall -pedantic -std=c++98 -g

all: runme

runme: main.o transformation_matrix.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp transformation_matrix.h
transformation_matrix.o: transformation_matrix.h transformation_matrix.cpp

test: runme
	./runme

clean:
	$(RM) runme *.o
