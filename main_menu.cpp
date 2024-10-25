#include "src/main_menu.h"

std::string choices[] = {"New Game", "Settings", "Quit"};

MainMenu::MainMenu(WINDOW* win)
    : Menu(win, 3, choices){}

int MainMenu::start(){
    int choice;
    choice = Menu::start();
    switch(choice){
        case 1:
        {
            /*start game*/
            return 0;
        }
        case 2:
        {
            /*settings*/
            return -1;
        }
        case 3:
        {
            /*quit*/
            return -1;
        }
    }
    return -1;
}
