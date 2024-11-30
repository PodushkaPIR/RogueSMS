#pragma once
#include <ncurses.h>

class AbstractWindow {
protected:
    WINDOW* _window;
    int _width, _height, _start_x, _start_y;

public:
    AbstractWindow(int width, int height, int start_x, int start_y);
    WINDOW* get_window() const;
    virtual ~AbstractWindow();
    virtual void render() const = 0;
    virtual void refresh_window() const;
};

