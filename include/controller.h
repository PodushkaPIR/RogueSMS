#pragma once
#include<ncurses.h>
#include<vector>
#include "player.h"


class Controller {
private:
    Player _player;
    std::vector<Unit> _entitys={};
    WINDOW* _window_game;
public:
    Controller(WINDOW* window_game)
    : _window_game(window_game), _player(window_game, 1, 1, '@'){}

    bool player_input();

    void display();

};
