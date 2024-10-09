all: main

main: main.cpp
	g++ -lncurses main.cpp -o result

