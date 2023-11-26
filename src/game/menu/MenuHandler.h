#ifndef OOP_MENUHANDLER_H
#define OOP_MENUHANDLER_H

#include "MainMenu.h"
#include "SettingsMenu.h"
#include "PauseMenu.h"
#include "VictoryMenu.h"
#include "DefeatMenu.h"

class Game;

class MenuHandler {
public:
    MenuHandler();
    ~MenuHandler();

    menu_options run_menu(Game* game, Menu* menu);
};


#endif //OOP_MENUHANDLER_H
