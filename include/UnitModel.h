#pragma once
#include <ncurses.h>

class UnitModel {
private:
    int _x, _y;
    char _symbol;

public:
    UnitModel(int x, int y, char symbol);
    virtual ~UnitModel() = default;
    
    void move(int dx, int dy);
    int get_x() const;
    int get_y() const;
    char get_symbol() const;
};
