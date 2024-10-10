#include <ncurses.h>
#include "src/menu.h"
#include <string>

int Menu::start(WINDOW* menuwin){
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    int menu_lines = 3;
    std::string choices[menu_lines] = {"New Game", "Settings", "Quit"};
    int choice;
    int highlight = 0;
    while(true){
        for(int i = 0; i < menu_lines; i++){
            if(i == highlight){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
        switch(choice){
            case KEY_UP:
                {
                highlight--;
                highlight = ((highlight < 0) ? menu_lines - 1 : highlight);
                break;
                }
            case KEY_DOWN:
                {
                highlight++;
                highlight = ((highlight >= menu_lines) ? 0 : highlight);
                break;
                }
            case KEY_RIGHT:
                {
                highlight = menu_lines - 1;
                break;
                }
            case KEY_LEFT:
                {
                highlight = 0;
                break;
                }
            default:
            {
                break;
            }
        }
        if(choice == 10){
            break;
        }
    }
    if (highlight == (menu_lines - 1)){
        return -1;
    }
    return highlight;
}