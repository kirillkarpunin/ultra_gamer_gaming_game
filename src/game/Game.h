#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "../entities/player/Player.h"
#include "structure/Level.h"

#include "updater/Updater.h"

#include "../input_output/Config.h"
#include "../input_output/input_interface/ConsoleInput.h"
#include "../input_output/input_interface/FileInput.h"

class Game {
private:
    Player* player;
    Level* level;

    Renderer* renderer;
    Printer* printer;
    Updater* updater;

    IInput* input;
    Config* config;

    std::pair<int, int> playground_size;

    bool saved_progress;
    bool game_is_running;
    int level_n;

    void change_input();

    void pause_menu();
    void victory_menu();
    void defeat_menu();
    void settings_menu();

    void game_loop();

    void create_new_level();
    void new_size();

public:
    Game();

    void main_menu();

    ~Game();
};


#endif //OOP_GAME_H
