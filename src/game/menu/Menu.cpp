#include "Menu.h"

void Menu::option_up() {
    curr_option--;
    if (curr_option < 0) curr_option = (int)options.size()-1;
    notify();
}

void Menu::option_down() {
    curr_option++;
    if (curr_option > (int)options.size()-1) curr_option = 0;
    notify();
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
    observer = nullptr;
    curr_option = 0;
    active = true;
}

void Menu::add_observer(IObserver *observer_) {
    observer = observer_;
}

void Menu::notify() {
    observer->update(this);
}

std::ostream &operator<<(std::ostream &stream, Menu &menu) {
    menu.print();
    return stream;
}

void Menu::print() {
    std::cout << label;

    for (int i = 0; i < options.size(); i++){
        std::cout << "\t";
        if (i == curr_option) std::cout << "> ";
        std::cout << options[i].first << std::endl;
    }
}


