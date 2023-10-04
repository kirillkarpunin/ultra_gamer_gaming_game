#include "Player-Manager.h"
#include <iostream>

int main() {
    Player player;
    Playground playground(15, 15);
    PlayerManager manager(player, playground);

    playground.print_map();
    std::cout << "----\n";

    manager.move(right);

    playground.print_map();
    std::cout << "----\n";

    manager.move(down);
    playground.print_map();
    std::cout << "----\n";

    return 0;
}