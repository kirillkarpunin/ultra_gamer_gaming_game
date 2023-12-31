#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "level/Level.h"
#include "../input_output/InputHandler.h"

#include "../input_output/Renderer.h"
#include "updater/Updater.h"

#include "menu/MenuHandler.h"

class Game {
private:
    friend MenuHandler;

    Player* player;
    Level* level;

    MenuHandler* menu_handler;
    InputHandler* input_handler;

    Updater* updater;

    std::pair<int, int> playground_size;

    bool saved_progress;
    bool game_is_running;
    bool restart;

    void create_new_level();

    void new_size();

    void defeat_menu();
    void victory_menu();
    void pause_menu();
    void settings_menu();
    void logger_menu();
    void main_menu();

    void game_loop();

public:
    Game();
    ~Game();

    void init();
};


#endif //OOP_GAME_H
