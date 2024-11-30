#include "../include/FieldModel.h"

FieldModel::FieldModel(int width, int height) 
    : _width(width), _height(height) {}

int FieldModel::get_width() const {
    return _width;
}

int FieldModel::get_height() const {
    return _height;
}
