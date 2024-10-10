#pragma once

#include <ncurses.h>

class Program {
private:
    int _width, _height;

public:
    Program();
    // void initialize();

    int get_width();
    int get_height();
};
