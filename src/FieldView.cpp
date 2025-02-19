#include "../include/FieldView.h"

FieldView::FieldView(const int width, const int height, const int start_x, const int start_y)
    : AbstractWindow(width, height, start_x, start_y) {}

void FieldView::render() const {
    mvwprintw(window_, 0, 1, "RogueSMS");
}

void FieldView::viewBounds() const {
    box(window_, 0, 0);
}
