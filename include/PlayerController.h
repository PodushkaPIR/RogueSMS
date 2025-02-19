#pragma once
#include <Controller.h>
#include <FieldModel.h>
#include <FieldView.h>
#include <PlayerModel.h>

#include <utility>

class PlayerController final : Controller {
private:
    FieldView view_;
    FieldModel model_;
    PlayerModel player_;

public:
    PlayerController(const FieldView &view, const FieldModel model,
                     const PlayerModel &player)
        : view_(view), model_(model), player_(player) {
    }

    void run() override;

    void drawUnit(int x, int y, char symbol) const;

    void runLogic(bool flag);

    void move_player(int dx, int dy);
};
