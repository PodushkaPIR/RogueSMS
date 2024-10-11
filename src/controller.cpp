#include "../include/controller.h"

bool Controller::player_input() {
    int choice = wgetch(_window_game);
    switch (choice) {
        case KEY_UP:
            _player.move_on_y(-1);
            break;
        case KEY_DOWN:
            _player.move_on_y(1);
            break;
        case KEY_LEFT:
            _player.move_on_x(-1);
            break;
        case KEY_RIGHT:
            _player.move_on_x(1);
            break;
        case '\n':
            return false;
        default:
            break;
    }

    return true;
}

void Controller::display() {
    _player.display();
    for (auto& entity : _entitys)
        entity.display();
}
