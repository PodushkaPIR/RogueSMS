#pragma once
#include "UnitModel.h"

class PlayerModel final : public UnitModel {
public:
    PlayerModel(const int x, const int y, const char symbol)
        : UnitModel(x, y, symbol) {
    }
};
