CC = g++
BUILD_DIR = build
START_DIR = ${CURDIR}

all: rebase

rebase:output
	mkdir -p ${BUILD_DIR}
	mv *.o ${BUILD_DIR}
	mv ./result ${BUILD_DIR}

output: main.o player.o unit.o controller.o menu.o
	${CC} -o result main.o player.o unit.o controller.o menu.o -lncurses

main.o: main.cpp
	${CC} -c ${START_DIR}/main.cpp

player.o: player.cpp
	${CC} -c ${START_DIR}/player.cpp

unit.o: unit.cpp
	${CC} -c ${START_DIR}/unit.cpp

controller.o: controller.cpp
	${CC} -c ${START_DIR}/controller.cpp

menu.o: menu.cpp
	${CC} -c ${START_DIR}/menu.cpp

clean:
	rm -rf ${BUILD_DIR}/
