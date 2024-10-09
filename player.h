#include <ncurses.h>
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
public:
    Player(WINDOW*, int, int, char);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void display();

    int get_move();

private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW * curwin;
};

Player::Player(WINDOW * win, int y, int x, char c)
    : curwin(win), yLoc(y), xLoc(x), character(c) {
    getmaxyx(curwin, yMax, xMax);
    keypad(curwin, true);
}

void Player::move_up() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc--;
    if (yLoc < 1) {
        yLoc = 1;
    }
}

void Player::move_down() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    yLoc++;
    if (yLoc > yMax - 2) {
        yLoc = yMax - 2;
    }
}

void Player::move_left() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc--;
    if (xLoc < 1) {
        xLoc = 1;
    }
}

void Player::move_right() {
    mvwaddch(curwin, yLoc, xLoc, ' ');
    xLoc++;
    if (xLoc > xMax - 2) {
        xLoc = xMax - 2;
    }
}

void Player::display() {
    mvwaddch(curwin, yLoc, xLoc, character);
}

int Player::get_move() {
    int choice = wgetch(curwin);
    switch(choice) {
        case KEY_UP:
            move_up();
            break;
        case KEY_DOWN:
            move_down();
            break;
        case KEY_LEFT:
            move_left();
            break;
        case KEY_RIGHT:
            move_right();
            break;
        default:
            break;
    }
    return choice;
}

#endif
