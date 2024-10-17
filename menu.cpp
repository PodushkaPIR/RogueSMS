#include "src/menu.h"
#include <fstream>

Menu::Menu() = default;
Menu::Menu(WINDOW* win, int lines, std::string* array_choices)
    : menuwin(win), menu_lines(lines), choices(array_choices){}

void Menu::display(int highlight){
    for(int i = 0; i < menu_lines; i++){
            if(i == highlight){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            
            wattroff(menuwin, A_REVERSE); 
        }
        refresh();
        wrefresh(menuwin);
}

int Menu::key_pressed_behavior(int key, int highlight){
    switch(key){
        case KEY_UP:
            {
            highlight--;
            highlight = ((highlight < 0) ? menu_lines - 1 : highlight);
            return highlight;
            }
        case KEY_DOWN:
            {
            highlight++;
            highlight = ((highlight >= menu_lines) ? 0 : highlight);
            return highlight;
            }
        case KEY_RIGHT:
            {
            highlight = menu_lines - 1;
            return highlight;
            }
        case KEY_LEFT:
            {
            highlight = 0;
            return highlight;
            }
        case 10:
            {
                return -1;
            }
        default:
        {
            break;
        }
    }
    return 0;
}

int Menu::get_pressed_key(){
    return wgetch(menuwin);
}

int Menu::working_cycle(){
        int pressed_key;
        int highlight = 0;
        while(true){
            display(highlight);
            int behavior = key_pressed_behavior(get_pressed_key(), highlight);
            if(behavior == -1){
                return highlight;
            }
            highlight = behavior;
        }
}

int Menu::start(){
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    std::ofstream out("debug.txt");
    out << "!";
    //out << *choices;
    out << "!";
    return working_cycle();
}





