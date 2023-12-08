#ifndef OOP_MENUHANDLER_H
#define OOP_MENUHANDLER_H

#include "MainMenu.h"
#include "SettingsMenu.h"
#include "PauseMenu.h"
#include "VictoryMenu.h"
#include "DefeatMenu.h"
#include "LoggerMenu.h"

class Game;

class MenuHandler {
private:
    IObserver* observer;
public:
    MenuHandler();
    ~MenuHandler();

    void set_observer(IObserver* observer_);
    menu_options run_menu(Game* game, Menu* menu);
};


#endif //OOP_MENUHANDLER_H
