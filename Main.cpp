#include "entities/player/Player-Manager.h"
#include <iostream>

int main() {
    Playground playground(20, 10);
    Player player;
    PlayerManager player_manager(player, playground);

    playground.print_map();

    return 0;
}