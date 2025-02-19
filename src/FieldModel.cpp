#include "../include/FieldModel.h"

FieldModel::FieldModel(const int width, const int height)
    : width_(width), height_(height) {}

int FieldModel::get_width() const {
    return width_;
}

int FieldModel::get_height() const {
    return height_;
}
