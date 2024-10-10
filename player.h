#pragma once

#include "unit.h"

class Player: public Unit {
public:
    Player(WINDOW*, int, int, char);

    int get_move();
    void keys();
};
