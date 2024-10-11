#include "../include/program.h"

Program::Program() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    getmaxyx(stdscr, _height, _width);
}

int Program::get_width() {
    return _width;
}
int Program::get_height() {
    return _height;
}
