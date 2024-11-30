#pragma once
#include "AbstractWindow.h"

class FieldView : public AbstractWindow {
public:
    FieldView(int width, int height, int start_x, int start_y);

    void render() const override;

    void draw_unit(int x, int y, char symbol) const;
};
