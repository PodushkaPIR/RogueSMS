#include "../include/UnitModel.h"

UnitModel::UnitModel(int x, int y, char symbol)
    : _x(x), _y(y), _symbol(symbol) {

}

void UnitModel::move(int dx, int dy) {
    _x += dx;
    _y += dy;
}

int UnitModel::get_x() const {
    return _x;
}

int UnitModel::get_y() const {
    return _y;
}

char UnitModel::get_symbol() const {
    return _symbol;
}
