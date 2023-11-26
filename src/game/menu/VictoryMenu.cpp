#include "VictoryMenu.h"

void VictoryMenu::create_options() {
    options = {
            {"next level", play_game},
            {"main menu", return_main_menu}
    };
}
