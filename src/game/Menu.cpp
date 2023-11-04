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

int Menu::get_curr_option() const {
    return curr_option;
}

std::vector<option>& Menu::get_options(){
    return options;
}

menu_options Menu::choose_option() const {
    return options[curr_option].second;
}

void Menu::close() {
    active = false;
}

bool Menu::is_active() const {
    return active;
}

Menu::~Menu() = default;
