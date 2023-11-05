#include "Printer.h"

Printer::Printer() = default;
Printer::~Printer() = default;


void Printer::print_logo() {
    std::cout << "\n\t| DUNGEON CRAWLER |\n\n";
}

void Printer::print_pause_label() {
    std::cout << "\n\t| PAUSE |\n\n";
}

void Printer::print_settings_label() {
    std::cout << "\n\t| SETTINGS |\n\n";
}

void Printer::print_invalid_config() {
    std::cout << "Invalid config file";
}
