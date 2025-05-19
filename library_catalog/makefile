CC=gcc
CFLAGS=-Wall -Wextra
EXE_FILE=prog

all: $(EXE_FILE)

$(EXE_FILE): hashmap.o book.o library.o main.o
	$(CC) $(CFLAGS) hashmap.o book.o library.o main.o -o $(EXE_FILE)

hashmap.o: hashmap.hpp hashmap.cpp
	$(CC) $(CFLAGS) -c hashmap.cpp

book.o: book.h book.c
	$(CC) $(CFLAGS) -c book.cpp

library.o: hashmap.hpp book.hpp library.hpp library.cpp
	$(CC) $(CFLAGS) -c library.cpp

main.o: library.hpp main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o $(EXE_FILE)
