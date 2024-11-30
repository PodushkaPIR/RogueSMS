#include "../include/GameController.h"

GameController::GameController(FieldView* fv, FieldModel* fm, MenuView* mv, PlayerModel* pm)
    : _field_view(fv), _field_model(fm), _menu(mv), _player(pm) {}

void GameController::show_menu() {
    int ch;
    bool in_menu = true;

    refresh();
    _menu->render();

    while(in_menu) {
        box(_menu->get_window(), 0, 0);
        ch = getch();

        _menu->handle_input(ch);
        if (ch == '\n') {
            int choice =_menu->get_selected_option();
            if (choice == 0) {
                in_menu = false;
            }
            else if (choice == 1) {
                endwin();
                std::exit(0);
            }
        }

        _menu->render();
    }
    clear();
}

void GameController::run() {
    show_menu();
    
    int ch;
    bool running = true;

    refresh();
    _field_view->render();

    while (running) {
        box(_field_view->get_window(), 0, 0);

        _field_view->draw_unit(_player->get_x(), _player->get_y(), _player->get_symbol());
        _field_view->refresh_window();

        ch = getch();
        switch(ch) {
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
                running = false;
                break;
        }

        _field_view->render();
    }
    clear();
}

void GameController::move_player(int dx, int dy) {
    int new_x = _player->get_x() + dx;
    int new_y = _player->get_y() + dy;

    if (new_x <= 0 || new_x >= _field_model->get_width() - 1 || \
        new_y <= 0 || new_y >= _field_model->get_height() - 1) {
        return;
    }

    _field_view->draw_unit(_player->get_x(), _player->get_y(), ' ');

    _player->move(dx, dy);
}
