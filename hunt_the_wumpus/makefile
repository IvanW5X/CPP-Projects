CC=g++ -std=c++11 -g
exe=asm4

all: $(exe)

$(exe): bats.o event.o game.o gold.o room.o stalactites.o wumpus.o main.cpp
	$(CC) bats.o event.o game.o gold.o room.o stalactites.o wumpus.o main.cpp -o $(exe)

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

stalactites.o: stalactites.h stalactites.cpp
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

clean:
	rm -f *.o $(exe)