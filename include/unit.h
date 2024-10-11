#pragma once
#include <ncurses.h>


class Unit {
protected:
    int _xloc, _yloc, _xmax, _ymax;
    char _character;
    WINDOW* _curwin;

public:
    Unit();
    Unit(WINDOW*, int, int, char);

    virtual void move_on_y(int delta);
    virtual void move_on_x(int delta);

    void display();
    // int get_xloc();
    // int get_yloc();
    // int get_xmax();
    // int get_ymax();
    // char get_character();
    // WINDOW* get_curwin();

};
