CC = g++
BUILD_DIR = build
START_DIR = ${CURDIR}

all: rebase

rebase:output
	mkdir -p ${BUILD_DIR}
	mv *.o ${BUILD_DIR}
	mv ./result ${BUILD_DIR}

output: main.o player.o unit.o controller.o menu.o main_menu.o
	${CC} -o result main.o player.o unit.o controller.o menu.o main_menu.o -lncurses 

main.o: main.cpp
	${CC} -g -c ${START_DIR}/main.cpp

player.o: player.cpp
	${CC} -g -c ${START_DIR}/player.cpp

unit.o: unit.cpp
	${CC} -g -c ${START_DIR}/unit.cpp

controller.o: controller.cpp
	${CC} -g -c ${START_DIR}/controller.cpp

menu.o: menu.cpp
	${CC} -g -c ${START_DIR}/menu.cpp

main_menu.o: main_menu.cpp
	${CC} -g -c ${START_DIR}/main_menu.cpp

clean:
	rm -rf ${BUILD_DIR}/
