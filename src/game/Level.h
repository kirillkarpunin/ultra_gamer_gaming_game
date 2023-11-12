#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H

#include "../entities/player/PlayerManager.h"

#include "../world/map/Playground.h"
#include "../world/map/MapGenerator.h"

class Game;

class Level {
private:
    friend Game;

    PlayerManager* player_manager;
    Playground* playground;
    MapGenerator* map_generator;
public:
    Level(Player* player);
    ~Level();

    void new_level(Player* player, std::pair<int, int> playground_size);
};


#endif //OOP_LEVEL_H
