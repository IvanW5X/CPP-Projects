CC=g++
EXE_FILE=out

all: $(EXE_FILE)

$(EXE_FILE): coffee.o display.o menu.o order.o shop.o prog.cpp
	$(CC) coffee.o display.o menu.o order.o shop.o prog.cpp -o $(EXE_FILE)

coffee.o: coffee.h coffee.cpp
	$(CC) -c coffee.cpp

display.o: display.h display.cpp
	$(CC) -c display.cpp

menu.o: menu.h menu.cpp
	$(CC) -c menu.cpp

order.o: order.h order.cpp
	$(CC) -c order.cpp

shop.o: shop.h shop.cpp
	$(CC) -c shop.cpp

clean:
	rm -f *.o $(EXE_FILE)