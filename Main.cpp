#include "entities/player/Player-Manager.h"
#include "world/map/MapGenerator.h"
#include "input_output/Renderer.h"

#include <mgetch.h>
#include <cstdlib>



int main() {
    Playground playground;
    Player player;

    MapGenerator generator(playground);
    PlayerManager player_manager(player, playground);
    Renderer renderer(player_manager, playground);

    generator.generate();

    bool game = true;
    while(game && !player_manager.is_defeated()) {

        system("clear");
        renderer.print_logo();
        renderer.print_map();
        renderer.print_player_info();

        int ch = mgetch();

        switch (ch)
        {
            case 27:
                game = false;
                break;

            case 'w':
                player_manager.move(up);
                break;
            case 'a':
                player_manager.move(left);
                break;
            case 's':
                player_manager.move(down);
                break;
            case 'd':
                player_manager.move(right);
                break;
            case ' ':
                player_manager.move(none);
                break;

        }
    }

    return 0;
}