#include "Menu.h"

void Menu::option_up() {
    curr_option--;
    if (curr_option < 0) curr_option = (int)options.size()-1;
}

void Menu::option_down() {
    curr_option++;
    if (curr_option > (int)options.size()-1) curr_option = 0;
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
Menu::Menu() {
    curr_option = 0;
    active = true;
}