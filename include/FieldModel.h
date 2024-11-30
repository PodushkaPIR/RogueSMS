#pragma once
#include "AbstractWindow.h"

class FieldModel {
private:
    int _width, _height;

public:
    FieldModel(int width, int height);
    int get_width() const;
    int get_height() const;
};
