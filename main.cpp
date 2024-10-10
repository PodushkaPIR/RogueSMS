#include <ncurses.h>
#include "src/program.h"
#include "src/controller.h"
#include "src/Utility.h"

int main() {
    // NCURSES start
    Program program;

    WINDOW* playwin = newwin(PLAYWIN_HEIGHT, PLAYWIN_WIDTH , PLAYWIN_Y, PLAYWIN_X);
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
