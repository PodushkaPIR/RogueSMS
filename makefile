CC = g++
all: output

output: main.o player.o unit.o
	${CC} -o result main.o player.o unit.o -lncurses

main.o: main.cpp player.h
	${CC} -c main.cpp

player.o: player.cpp player.h
	${CC} -c player.cpp

unit.o: unit.cpp unit.h
	${CC} -c unit.cpp

clean:
	rm *.o
