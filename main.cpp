#include <ncurses.h>
#include "src/player.h"
#include "src/controller.h"
#include "src/main_menu.h"

int main() {
    // NCURSES start
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    int height = 8, width = xMax - 12, cursorY = 1, cursorX = 1;
    WINDOW* playwin = newwin(8, xMax-12, yMax-8, 5);
    MainMenu menu = MainMenu(playwin);
    int next_window = menu.start();
    clear();
    wclear(playwin);
    refresh();
    //if для обработки выбора следующего окна
    if (next_window == 0){
        box(playwin, 0, 0);
        refresh();

        Controller controller(playwin);

        do {
            //controller.AI();
            controller.display();
            wrefresh(playwin);
        } while (controller.player_input());
    }
    
    // END
    endwin();

    return 0;
}
