#include "../include/GameController.h"
#include "../include/Utility.h"

int main() {
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);

    std::vector<std::string> options = { "Start", "Quit" };

    FieldView field_view(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_START_X, SCREEN_START_Y);

    FieldModel field_model(SCREEN_WIDHT, SCREEN_HEIGHT);

    MenuView menu_view(MENU_WIDTH, MENU_HEIGHT, MENU_START_X, MENU_START_Y, options);

    PlayerModel player(5, 5, '@');

    GameController controller(&field_view, &field_model, &menu_view, &player);
    controller.run();

    endwin();
    return 0;
}

