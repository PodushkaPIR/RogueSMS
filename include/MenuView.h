#pragma once
#include "AbstractWindow.h"
#include <vector>
#include <string>

class MenuView : public AbstractWindow {
private:
    std::vector<std::string> _options;
    int _selected_option;

public:
    MenuView(int width, int height, int start_x, int start_y, const std::vector<std::string>& options);
    int get_selected_option() const;
    void render() const override;
    void handle_input(int ch);
};
