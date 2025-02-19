#include "MenuController.h"

void MenuController::run() {
    refresh();
    menuView_.render();
    bool in_menu = true;
    while (in_menu) {
        box(menuView_.get_window(), 0, 0);
        const int ch = getch();

        menuView_.handle_input(ch);
        if (ch == '\n') {
            if (const int choice = menuView_.get_selected_option(); choice == 0) {
                in_menu = false;
            } else if (choice == 1) {
                endwin();
                std::exit(0);
            }
        }

        menuView_.render();
    }
    clear();
}
