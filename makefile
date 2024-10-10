CC = g++
all: output

output: main.o player.o unit.o controller.o
	${CC} -o result main.o player.o unit.o controller.o -lncurses -g

main.o: main.cpp player.h
	${CC} -c main.cpp

player.o: player.cpp player.h
	${CC} -c player.cpp

unit.o: unit.cpp unit.h
	${CC} -c unit.cpp

controller.o: controller.cpp controller.h
	${CC} -c controller.cpp

clean:
	rm *.o
