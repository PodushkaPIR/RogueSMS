#pragma once
#include <ncurses.h>
#include <string>

class Menu{
    protected: 
        WINDOW* menuwin;
        int menu_lines;
        std::string* choices;
        virtual int working_cycle();
        virtual void display(int highlight);
        virtual int get_pressed_key();
        virtual int key_pressed_behavior(int key, int highlight);

    public:
        Menu();
        Menu(WINDOW*, int , std::string*);
        virtual int start();
};