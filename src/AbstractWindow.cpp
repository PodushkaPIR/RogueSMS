#include "../include/AbstractWindow.h"

AbstractWindow::AbstractWindow(const int width, const int height, const int start_x, const int start_y)
    : width_(width), height_(height), start_x_(start_x), start_y_(start_y) {
    window_ = newwin(height_, width_, start_y_, start_x_);
    box(window_, 0, 0);
}

AbstractWindow::~AbstractWindow() {
    delwin(window_);
}

void AbstractWindow::refresh_window() const {
    wrefresh(window_);
}

WINDOW *AbstractWindow::get_window() const {
    return window_;
}
