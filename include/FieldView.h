#pragma once
#include "AbstractWindow.h"

class FieldView final : public AbstractWindow {
public:
    FieldView(int width, int height, int start_x, int start_y);

    void render() const override;

    void viewBounds() const;
};
