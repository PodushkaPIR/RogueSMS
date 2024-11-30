#include "../include/FieldView.h"

FieldView::FieldView(int width, int height, int start_x, int start_y)
    : AbstractWindow(width, height, start_x, start_y) {}

void FieldView::render() const {
    mvwprintw(_window, 0, 1, "RogueSMS");
}

void FieldView::draw_unit(int x, int y, char symbol) const {
    mvwaddch(_window, y, x, symbol);
}
