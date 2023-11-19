#include "Menu.h"

Menu::Menu(std::vector<option> options_) {
    options = std::move(options_);
    curr_option = 0;
    active = true;
}

void Menu::option_up() {
    curr_option--;
    if (curr_option < 0) curr_option = (int)options.size()-1;
}

void Menu::option_down() {
    curr_option++;
    if (curr_option > (int)options.size()-1) curr_option = 0;
}

int Menu::get_curr_pos() const {
    return curr_option;
}

menu_options Menu::choose_option() const {
    return options[curr_option].second;
}

std::vector<option>& Menu::get_options(){
    return options;
}

void Menu::close() {
    active = false;
}

bool Menu::is_active() const {
    return active;
}

menu_options Menu::update(keys key) {
    switch (key) {
        case esc_key:
            return resume;
        case up_key:
            option_up();
            return nothing;
        case down_key:
            option_down();
            return nothing;
        case wait_key:
            return choose_option();
        default:
            return nothing;
    }
}

Menu::~Menu() = default;
