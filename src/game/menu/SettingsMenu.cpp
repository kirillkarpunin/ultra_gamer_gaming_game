#include "SettingsMenu.h"

void SettingsMenu::init() {
    options = {
            {"change field size", change_size},
            {"back", resume}
    };

    label = "\n\t| SETTINGS |\n\n";
}
