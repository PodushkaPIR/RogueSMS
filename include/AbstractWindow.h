#pragma once
#include <ncurses.h>

class AbstractWindow {
protected:
    WINDOW *window_;
    int width_, height_, start_x_, start_y_;

public:
    AbstractWindow(int width, int height, int start_x, int start_y);

    [[nodiscard]] WINDOW *get_window() const;

    virtual ~AbstractWindow();

    virtual void render() const = 0;

    virtual void refresh_window() const;
};
