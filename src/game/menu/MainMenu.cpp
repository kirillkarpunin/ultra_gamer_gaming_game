#include "MainMenu.h"

void MainMenu::create_options() {
    options = {
            {"play", play_game},
            {"settings", settings},
            {"exit", exit_game},
    };
}
