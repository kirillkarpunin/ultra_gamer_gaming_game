#include "PauseMenu.h"

void PauseMenu::create_options() {
    options = {
            {"resume", resume},
            {"new game", new_game},
            {"settings", settings},
            {"return to main menu", return_main_menu},
    };
}
