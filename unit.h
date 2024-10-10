#pragma once
#include <ncurses.h>

class Unit {
public:
    Unit(WINDOW*, int, int, char);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void display();

    int get_move();

protected:
    int _xloc, _yloc, _xmax, _ymax;
    char _character;
    WINDOW * _curwin;
};
