#include "VictoryMenu.h"

void VictoryMenu::init() {
    options = {
            {"next level", play_game},
            {"main menu", return_main_menu}
    };

    label = "\n\t| VICTORY |\n\n";
}
