#include "Level.h"

void Level::new_level(Player *player, std::pair<int, int> playground_size) {
    int passed_levels = player_manager->get_passed_levels() + 1;

    delete playground;
    delete player_manager;

    playground = new Playground(playground_size.first, playground_size.second);
    player_manager = new PlayerManager(*player, *playground);

    while (player_manager->get_passed_levels() != passed_levels){
        player_manager->pass_level();
    }

    map_generator->generate(*playground);
    player_manager->set_position(playground->get_entrance_point());
}

Level::~Level() {
    delete playground;
    delete player_manager;
    delete map_generator;
}

Level::Level(Player *player) {
    playground = new Playground;
    player_manager = new PlayerManager(*player, *playground);
    map_generator = new MapGenerator;
}
