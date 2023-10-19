#include "Renderer.h"

void Renderer::print_map(){
    for (int i = 0; i < playground.get_size().second; i++)
    {
        for (int j = 0; j < playground.get_size().first; j++)
        {
            if (player_manager.get_position() == std::pair<int, int>{j,i}){
                std::cout << "@ ";
            }
            else {
                switch (playground.get_cell_type({j,i}))
                {
                    case empty: {
                        std::cout << ". ";
                        break;
                    }
                    case obstacle: {
                        std::cout << "# ";
                        break;
                    }
                    case trap: {
                        std::cout << "^ ";
                        break;
                    }
                    case chest: {
                        std::cout << "$ ";
                        break;
                    }
                    case entrance: {
                        std::cout << "o ";
                        break;
                    }
                    case exit_: {
                        std::cout << "x ";
                        break;
                    }
                    case portal: {
                        std::cout << "% ";
                        break;
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}

void Renderer::print_player_info() {
    std::cout << std::endl;

    std::cout << "Health:\t" << player_manager.get_health() << std::endl;
    std::cout << "Armor:\t" << player_manager.get_armor() << std::endl;
    std::cout << "Damage:\t" << player_manager.get_damage() << std::endl;
    std::cout << "Bombs:\t" << player_manager.get_bombs() << std::endl;
}

void Renderer::print_logo() {
    std::cout << "| DUNGEON CRAWLER |\n\n";
}

Renderer::Renderer(PlayerManager &player_manager_, Playground& playground_): player_manager(player_manager_), playground(playground_) {}

Renderer::~Renderer() = default;