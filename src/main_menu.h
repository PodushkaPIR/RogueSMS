#pragma once
#include <ncurses.h>
#include <string>
#include "menu.h"

class MainMenu : public Menu{
    public:
        MainMenu(WINDOW*);
        int start() override;
};