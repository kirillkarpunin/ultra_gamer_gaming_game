#include "Player-Manager.h"
#include <iostream>

int main() {
    Player player;
    Playground playground(18, 1);

    PlayerManager player_manager(player, playground);

    playground.print_map();

    return 0;
}