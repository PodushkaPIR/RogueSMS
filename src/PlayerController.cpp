#include "PlayerController.h"
#include <ncurses.h>

#include <iostream>

void PlayerController::run() {
    refresh();
    view_.render();
    view_.viewBounds();
    drawUnit(player_.get_x(), player_.get_y(), '@');
    view_.refresh_window();
    runLogic(true);
}

void PlayerController::drawUnit(const int x, const int y,
                                const char symbol) const {
    mvwaddch(view_.get_window(), y, x, symbol);
}

void PlayerController::runLogic(bool flag) {
    while (flag) {
        view_.viewBounds();
        drawUnit(player_.get_x(), player_.get_y(), '@');
        view_.refresh_window();
        switch (int ch = getch()) {
            case KEY_UP:
                move_player(0, -1);
                break;
            case KEY_DOWN:
                move_player(0, 1);
                break;
            case KEY_RIGHT:
                move_player(1, 0);
                break;
            case KEY_LEFT:
                move_player(-1, 0);
                break;
            case 'q':
                flag = false;
                break;
        }
    }
}

void PlayerController::move_player(const int dx, const int dy) {
    const int new_x = player_.get_x() + dx;
    const int new_y = player_.get_y() + dy;

    if (new_x <= 0 || new_x >= model_.get_width() - 1 || new_y <= 0 ||
        new_y >= model_.get_height() - 1) {
        return;
    }

    drawUnit(player_.get_x(), player_.get_y(), ' ');
    player_.move(dx, dy);
}
