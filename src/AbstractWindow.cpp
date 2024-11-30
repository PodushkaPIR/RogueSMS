#include "../include/AbstractWindow.h"

AbstractWindow::AbstractWindow(int width, int height, int start_x, int start_y) 
    : _width(width), _height(height), _start_x(start_x), _start_y(start_y) {
    _window = newwin(_height, _width, _start_y, _start_x);
    box(_window, 0, 0);
}

AbstractWindow::~AbstractWindow() {
    delwin(_window);
}

void AbstractWindow::refresh_window() const {
    wrefresh(_window);
}

WINDOW* AbstractWindow::get_window() const {
    return _window;
}
