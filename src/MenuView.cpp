#include "../include/MenuView.h"

MenuView::MenuView(int width, int height, int start_x, int start_y, const std::vector<std::string>& options)
    : AbstractWindow(width, height, start_x, start_y), _options(options), _selected_option(0) {}

int MenuView::get_selected_option() const {
    return _selected_option;
}

void MenuView::render() const {
    mvwprintw(_window, 0, 1, "Menu");
    for (int i = 0; i < _options.size(); ++i) {
        if (i == _selected_option) {
            wattron(_window, A_REVERSE);
            mvwprintw(_window, i + 2, 1, _options[i].c_str());
            wattroff(_window, A_REVERSE);
        }
        else {
            mvwprintw(_window, i + 2, 1, _options[i].c_str());
        }
    }
    refresh_window();
}

void MenuView::handle_input(int ch) {
    switch(ch) {
        case KEY_UP:
            if (_selected_option > 0) {
                _selected_option--;
            } 
        case KEY_DOWN:
            if (_selected_option < _options.size() - 1) {
                _selected_option++;
            }
    } 
}
