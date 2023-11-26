#include "DefeatMenu.h"

void DefeatMenu::create_options() {
    options = {
            {"try again", new_game},
            {"main menu", return_main_menu}
    };
}
