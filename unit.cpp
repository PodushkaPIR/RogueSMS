#include "unit.h"

Unit::Unit(WINDOW* win, int y, int x, char c)
    : _curwin(win), _yloc(y), _xloc(x), _character(c) {
    getmaxyx(_curwin, _ymax, _xmax);   
}

void Unit::move_up() {
    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _yloc--;
    if (_yloc < 1) {
        _yloc = 1;
    }
}

void Unit::move_down() {
    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _yloc++;
    if (_yloc > _ymax - 2) {
        _yloc = _ymax - 2;
    }
}

void Unit::move_left() {
    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _xloc--;
    if (_xloc < 1) {
        _xloc = 1;
    }
}

void Unit::move_right() {
    mvwaddch(_curwin, _yloc, _xloc, ' ');
    _xloc++;
    if (_xloc > _xmax - 2) {
        _xloc = _xmax - 2;
    }
}

void Unit::display() {
    mvwaddch(_curwin, _yloc, _xloc, _character);
}

