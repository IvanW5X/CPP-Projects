CC=g++
EXE_FILE=out

all: $(EXE_FILE)

$(EXE_FILE): dlist.o todo.o main.cpp
	$(CC) dlist.o todo.o main.cpp -o $(EXE_FILE)

dlist.o: node.h dlist.h dlist.cpp
	$(CC) -c dlist.cpp

todo.o: todo.h todo.cpp
	$(CC) -c todo.cpp

clean:
	rm -f *.o $(EXE_FILE)