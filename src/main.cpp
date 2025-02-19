#include "../include/GameController.h"
#include "../include/Utility.h"
#include "MenuController.h"
#include "PlayerController.h"

int main() {
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);
    const std::vector<std::string> options = {"Start", "Quit"};
    const auto menu_view = MenuView(MENU_WIDTH, MENU_HEIGHT, MENU_START_X,
                                    MENU_START_Y, options);
    auto menu = MenuController(menu_view);
    menu.run();
    const auto fv = FieldView(SCREEN_WIDHT, SCREEN_HEIGHT, SCREEN_START_X, SCREEN_START_Y);
    const auto fm = FieldModel(SCREEN_WIDHT,SCREEN_HEIGHT);
    const auto player = PlayerModel(5, 5, '@');
    auto field = PlayerController(fv, fm, player);
    field.run();
    endwin();
    return 0;
}
