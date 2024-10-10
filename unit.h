#pragma once
#include <ncurses.h>

class Unit {
public:
    Unit();
    Unit(WINDOW*, int, int, char);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void display();

    int get_xloc();
    int get_yloc();
    int get_xmax();
    int get_ymax();
    char get_character();
    WINDOW* get_curwin();

protected:
    int _xloc, _yloc, _xmax, _ymax;
    char _character;
    WINDOW * _curwin;
};
