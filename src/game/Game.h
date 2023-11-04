#ifndef OOP_GAME_H
#define OOP_GAME_H

#include "../entities/player/Player.h"
#include "../entities/player/PlayerManager.h"

#include "../world/map/Playground.h"
#include "../world/map/MapGenerator.h"

#include "../input_output/Renderer.h"

class Game {
private:
    Player* player;
    PlayerManager* player_manager;
    Playground* playground;
    MapGenerator* map_generator;
    Renderer* renderer;

    std::pair<int, int> playground_size;

    bool saved_progress;
    bool game_is_running;
    int level;

    void create_new_level();

    void pause_menu();
    void victory_menu();
    void defeat_menu();
    void settings_menu();

    void game_loop();

    void new_size();
    void see_controls();

public:
    Game();

    void main_menu();

    ~Game();
};


#endif //OOP_GAME_H
