#include "../include/unit.h"

Unit::Unit() = default;
// : _curwin(nullptr), _yloc(0), _xloc(0), _character(0), _ymax(0), _xmax(0) { };

Unit::Unit(WINDOW* win, int y, int x, char c)
    : _curwin(win), _yloc(y), _xloc(x), _character(c) {
    getmaxyx(_curwin, _ymax, _xmax);
}

void Unit::move_on_y(int delta) {
    if (_yloc + delta > _ymax - 2 || _yloc + delta < 1)
        return;

    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _yloc += delta;
}

void Unit::move_on_x(int delta) {
    if (_xloc + delta > _xmax - 2 || _xloc + delta < 1)
        return;

    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _xloc += delta;
}

void Unit::display() {
    mvwaddch(_curwin, _yloc, _xloc, _character);
}

// int Unit::get_xloc() { return _xloc; };
// int Unit::get_yloc() { return _yloc; };
// int Unit::get_xmax() { return _xmax; };
// int Unit::get_ymax() { return _ymax; };
// char Unit::get_character() { return _character; };
// WINDOW* Unit::get_curwin() { return _curwin; };
