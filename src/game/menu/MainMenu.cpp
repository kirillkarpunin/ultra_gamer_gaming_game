#include "MainMenu.h"

void MainMenu::init() {
    options = {
            {"play", play_game},
            {"settings", settings},
            {"exit", exit_game},
    };

    label = "\n\t| DUNGEON CRAWLER |\n\n";
}
