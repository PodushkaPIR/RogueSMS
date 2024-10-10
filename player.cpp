#include "src/player.h"

Player::Player(WINDOW* win, int y, int x, char c)
    : Unit(win, y, x, c) {
        keypad(_curwin, true);
    }

void Player::keys() {
    // Well i think this function may to be modifying for custom keymaps
    keypad(_curwin, true);
}

int Player::get_move() {
    int choice = wgetch(_curwin);
    switch(choice) {
        case KEY_UP:
            move_on_y(-1);
            break;
        case KEY_DOWN:
            move_on_y(1);
            break;
        case KEY_LEFT:
            move_on_x(-1);
            break;
        case KEY_RIGHT:
            move_on_x(1);
            break;
        default:
            break;
    }
    return choice;
}
