#include "Renderer.h"

void Renderer::print_map(){
    for (int i = 0; i < playground.get_size().second; i++)
    {
        for (int j = 0; j < playground.get_size().first; j++)
        {
            if (player_manager.get_position() == std::pair<int, int>{j,i}){
                std::cout << MAG << "@ ";
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
                        std::cout << RED << "^ ";
                        break;
                    }
                    case chest: {
                        std::cout << GRN << "$ ";
                        break;
                    }
                    case entrance: {
                        std::cout << CYN << "o ";
                        break;
                    }
                    case exit_: {
                        std::cout << CYN << "x ";
                        break;
                    }
                    case portal: {
                        std::cout << YEL << "% ";
                        break;
                    }
                }
            }
            std::cout << COLOR_RESET;
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

void Renderer::defeat_end() {
    std::cout << "                       ______\n"
                 "                    .-\"      \"-.\n"
                 "                   /            \\\n"
                 "       _          |              |          _\n"
                 "      ( \\         |,  .-.  .-.  ,|         / )\n"
                 "       > \"=._     | )(__/  \\__)( |     _.=\" <\n"
                 "      (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)\n"
                 "             \"=._ (_     ^^     _)\"_.=\"\n"
                 "                 \"=\\__|IIIIII|__/=\"\n"
                 "                _.=\"| \\IIIIII/ |\"=._\n"
                 "      _     _.=\"_.=\"\\          /\"=._\"=._     _\n"
                 "     ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )\n"
                 "      > _.=\"                            \"=._ <\n"
                 "     (_/                                    \\_)\n"
                 "\t\t\tDEFEAT\n\n";
}

void Renderer::victory_end() {
    std::cout << "                            _.--.\n"
                 "                        _.-'_:-'||\n"
                 "                    _.-'_.-::::'||\n"
                 "               _.-:'_.-::::::'  ||\n"
                 "             .'`-.-:::::::'     ||\n"
                 "            /.'`;|:::::::'      ||_\n"
                 "           ||   ||::::::'     _.;._'-._\n"
                 "           ||   ||:::::'  _.-!oo @.!-._'-.\n"
                 "           \\'.  ||:::::.-!()oo @!()@.-'_.|\n"
                 "            '.'-;|:.-'.&$@.& ()$%-'o.'\\U||\n"
                 "              `>'-.!@%()@'@_%-'_.-o _.|'||\n"
                 "               ||-._'-.@.-'_.-' _.-o  |'||\n"
                 "               ||=[ '-._.-\\U/.-'    o |'||\n"
                 "               || '-.]=|| |'|      o  |'||\n"
                 "               ||      || |'|        _| ';\n"
                 "               ||      || |'|    _.-'_.-'\n"
                 "               |'-._   || |'|_.-'_.-'\n"
                 "                '-._'-.|| |' `_.-'\n"
                 "                    '-.||_/.-'\n\n"
                 "\t\t\tVICTORY\n\n";
}

void Renderer::escape_end() {
    std::cout << "                .'``'.      ...\n"
                 "               :o  o `....'`  ;\n"
                 "               `. O         :'\n"
                 "                 `':          `.\n"
                 "                   `:.          `.\n"
                 "                    : `.         `.\n"
                 "                   `..'`...       `.\n"
                 "                           `...     `.\n"
                 "                               ``...  `.\n"
                 "                                    `````.\n"
                 "\t\t\tESCAPING\n\n";
}

Renderer::~Renderer() = default;