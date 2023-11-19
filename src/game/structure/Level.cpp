#include "Level.h"
#include "../Game.h"

Level::Level(Player* player) {
    playground = new Playground;
    player_manager = new PlayerManager(*player, *playground);
    map_generator = new MapGenerator;
}
Level::~Level(){
    delete playground;
    delete player_manager;
    delete map_generator;
}


void Level::new_level(Player* player, std::pair<int, int> playground_size) {
    delete playground;
    delete player_manager;

    playground = new Playground(playground_size.first, playground_size.second);
    player_manager = new PlayerManager(*player, *playground);

    map_generator->generate(*playground);
    player_manager->set_position(playground->get_entrance_point());
}
