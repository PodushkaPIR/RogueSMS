#include "../include/UnitModel.h"

UnitModel::UnitModel(int x, int y, char symbol)
    : x_(x), y_(y), symbol_(symbol) {
}

void UnitModel::move(const int dx, const int dy) {
    x_ += dx;
    y_ += dy;
}

int UnitModel::get_x() const {
    return x_;
}

int UnitModel::get_y() const {
    return y_;
}

char UnitModel::get_symbol() const {
    return symbol_;
}
