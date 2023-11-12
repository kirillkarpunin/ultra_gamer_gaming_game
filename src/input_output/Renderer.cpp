#include "Renderer.h"

void Renderer::render_map(Playground& playground, PlayerManager& player_manager){
    std::cout << std::endl;

    for (int i = 0; i < playground.get_size().second; i++)
    {
        for (int j = 0; j < playground.get_size().first; j++)
        {
            if (player_manager.get_position() == std::pair<int, int>{j,i}){
                std::cout << termcolor::magenta << "@ ";
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
                        std::cout << termcolor::red << "^ ";
                        break;
                    }
                    case chest: {
                        std::cout << termcolor::green << "$ ";
                        break;
                    }
                    case entrance: {
                        std::cout << termcolor::cyan << "o ";
                        break;
                    }
                    case exit_: {
                        std::cout << termcolor::cyan << "x ";
                        break;
                    }
                    case portal: {
                        std::cout << termcolor::yellow << "% ";
                        break;
                    }
                }
            }
            termcolor::reset(std::cout);
        }
        std::cout << std::endl;
    }
}

void Renderer::print_player_info(PlayerManager& player_manager) {
    std::cout << std::endl;

    std::cout << "Health:\t" << player_manager.get_health() << std::endl;
    std::cout << "Armor:\t" << player_manager.get_armor() << std::endl;
    std::cout << "Damage:\t" << player_manager.get_damage() << std::endl;
    std::cout << "Bombs:\t" << player_manager.get_bombs() << std::endl;
}

void Renderer::defeat_end(int level) {
    std::cout << "\n"
                 "\tDEFEAT\n"
                 "\tYOU DIED ON " << level << " LEVEL\n\n";
}

void Renderer::victory_end(int level) {
    std::cout << "\n"
                 "\tVICTORY\n"
                 "\tLEVEL " << level << " PASSED\n\n";
}

void Renderer::terminal_clear() {
    system("clear");
}

void Renderer::print_menu(Menu& menu) {
    for (auto elem : menu.get_options()){
        std::cout << "\t";
        if (elem == menu.get_options()[menu.get_curr_pos()]) std::cout << "> ";
        std::cout << elem.first << std::endl;
    }
}

void Renderer::print_level(int level) {
    std::cout << "\nLevel: " << level << std::endl;
}

Renderer::Renderer() = default;
Renderer::~Renderer() = default;