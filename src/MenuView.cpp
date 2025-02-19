#include "../include/MenuView.h"

int MenuView::get_selected_option() const {
    return selected_option_;
}

void MenuView::render() const {
    mvwprintw(window_, 1, 1, "Menu");
    for (int i = 0; i < options_.size(); ++i) {
        if (i == selected_option_) {
            wattron(window_, A_REVERSE);
            mvwprintw(window_, i + 2, 1, "%s", options_[i].c_str());
            wattroff(window_, A_REVERSE);
        } else {
            mvwprintw(window_, i + 2, 1, "%s", options_[i].c_str());
        }
    }
    refresh_window();
}

void MenuView::handle_input(const int ch) {
    switch (ch) {
        case KEY_UP:
            if (selected_option_ > 0) {
                selected_option_--;
            }
            break;
        case KEY_DOWN:
            if (selected_option_ < static_cast<int>(options_.size() - 1)) {
                selected_option_++;
            }
            break;
    }
}
