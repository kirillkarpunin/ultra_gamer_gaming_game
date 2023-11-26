#include "SettingsMenu.h"

void SettingsMenu::create_options() {
    options = {
            {"change field size", change_size},
            {"back", resume}
    };
}
