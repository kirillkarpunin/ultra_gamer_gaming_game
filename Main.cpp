#include "Player-Manager.h"
#include <iostream>

int main() {
    Player player;
    Playground playground(100, 100);
    PlayerManager manager(player, playground);

    playground.print_map();

    return 0;
}