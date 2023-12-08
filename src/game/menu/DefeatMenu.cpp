#include "DefeatMenu.h"

void DefeatMenu::init() {
    options = {
            {"try again", new_game},
            {"main menu", return_main_menu}
    };

    label = "\n\t| DEFEAT |\n\n";
}
