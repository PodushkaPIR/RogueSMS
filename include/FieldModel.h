#pragma once
#include "AbstractWindow.h"

class FieldModel {
private:
    int width_, height_;

public:
    FieldModel(int width, int height);

    [[nodiscard]] int get_width() const;

    [[nodiscard]] int get_height() const;
};
