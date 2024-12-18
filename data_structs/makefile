CC=g++ -Wall
EXE_FILE=out

all: $(EXE_FILE)

$(EXE_FILE): bst.o linked-list.o dyn-array.o hashmap.o main.cpp
	$(CC) bst.o linked-list.o dyn-array.o hashmap.o main.cpp -o $(EXE_FILE)

bst.o: types.h bst.h bst.cpp
	$(CC) -c bst.cpp

linked-list.o: types.h linked-list.h linked-list.cpp
	$(CC) -c linked-list.cpp

dyn-array.o: types.h dyn-array.h dyn-array.cpp
	$(CC) -c dyn-array.cpp

hashmap.o: types.h hashmap.h hashmap.cpp
	$(CC) -c hashmap.cpp

clean:
	rm -f *.o $(EXE_FILE)