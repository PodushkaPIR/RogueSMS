#include <ncurses.h>
#include "FieldView.h"
#include "FieldModel.h"
#include "MenuView.h"
#include "PlayerModel.h"

class GameController {
private:
    FieldView* _field_view;
    FieldModel* _field_model;
    MenuView* _menu;
    PlayerModel* _player;

    void move_player(int dx, int dy);

public:
    GameController(FieldView* fv, FieldModel* fm, MenuView* mv, PlayerModel* pm);
    void show_menu();
    void run();
};
