#include "player.h"

void Player::keys() {
    // Well i think this function may to be modifying for custom keymaps
    keypad(_curwin, true);
}

int Player::get_move() {
    int choice = wgetch(_curwin);
    switch(choice) {
        case KEY_UP:
            move_up();
            break;
        case KEY_DOWN:
            move_down();
            break;
        case KEY_LEFT:
            move_left();
            break;
        case KEY_RIGHT:
            move_right();
            break;
        default:
            break;
    }
    return choice;
}
