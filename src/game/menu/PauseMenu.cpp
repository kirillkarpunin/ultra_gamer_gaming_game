#include "PauseMenu.h"

void PauseMenu::init() {
    options = {
            {"resume", resume},
            {"new game", new_game},
            {"settings", settings},
            {"return to main menu", return_main_menu},
    };

    label = "\n\t| PAUSE |\n\n";
}
