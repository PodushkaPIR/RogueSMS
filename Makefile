CC = g++
all: output

output: main.o player.o unit.o
	${CC} -o result main.o player.o unit.o -lncurses

main.o: main.cpp
	${CC} -c main.cpp

player.o: player.cpp
	${CC} -c player.cpp

unit.o: unit.cpp
	${CC} -c unit.cpp

clean:
	rm *.o
