#include <ncurses.h>
#include "src/player.h"

int main() {
    // NCURSES start
    initscr();
    noecho();
    cbreak();
    // curs_set(0);

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    WINDOW *playwin = newwin(8, xMax-12, yMax-8, 5);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);

    Player p = Player(playwin, 1, 1, '@');
    do {
        p.display();
        wrefresh(playwin);
    } while (p.get_move() != '\n');

    // END
    getch();
    endwin();

    return 0;
}
