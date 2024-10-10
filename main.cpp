#include <ncurses.h>
#include "player.h"
#include "controller.h"

int main() {
    // NCURSES start
    initscr();
    noecho();
    cbreak();
    curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW* playwin = newwin(8, xMax-12, yMax-8, 5);
    box(playwin, 0, 0);
    refresh();

    Controller controller(playwin);

    do {
        //controller.AI();
        controller.display();
        wrefresh(playwin);
    } while (controller.player_input());

    // END
    getch();
    endwin();

    return 0;
}
