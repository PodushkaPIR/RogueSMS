#pragma once
#include <MenuView.h>

#include <utility>

#include "Controller.h"

class MenuController final : Controller {
private:
    MenuView menuView_;

public:
    explicit MenuController(const MenuView &menuView): menuView_(menuView) {
    }

    void run() override;
};
