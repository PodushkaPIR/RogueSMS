#pragma once
#include <string>
#include <vector>
#include "AbstractWindow.h"

class MenuView final : public AbstractWindow {
private:
    std::vector<std::string> options_;
    int selected_option_;

public:
    MenuView(const int width, const int height, const int start_x,
             const int start_y,
             const std::vector<std::string> &options)
        : AbstractWindow(width, height, start_x, start_y),
          options_(options),
          selected_option_(0) {
    }

    [[nodiscard]] int get_selected_option() const;

    void render() const override;

    void handle_input(int ch);
};
