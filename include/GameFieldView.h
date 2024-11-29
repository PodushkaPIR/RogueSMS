#pragma once
#include "AbstractWindow.h"

class GameFieldView : public AbstractWindow {
public:
    GameFieldView(int width, int height, int start_x, int start_y);

    void render() const override;

    void draw_unit(int x, int y, char symbol) const;
};
