#pragma once
#include <ncurses.h>

class UnitModel {
private:
    int x_, y_;
    char symbol_;

public:
    UnitModel(int x, int y, char symbol);

    virtual ~UnitModel() = default;

    void move(int dx, int dy);

    [[nodiscard]] int get_x() const;

    [[nodiscard]] int get_y() const;

    [[nodiscard]] char get_symbol() const;
};
