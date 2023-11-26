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
                IEvent* event = playground.get_cell_event({j,i});

                if (playground.get_entrance_point() == (std::pair<int,int>){j,i}){
                    std::cout << termcolor::cyan << "o ";
                }
                else if (playground.get_exit_point() == (std::pair<int,int>){j,i}){
                    std::cout << termcolor::cyan << "x ";
                }
                else if (event == nullptr){
                    std::cout << ". ";
                }
                else if (typeid(*event) == typeid(ExplodeWall)){
                    std::cout << "# ";
                }
                else if (typeid(*event) == typeid(Trap)){
                    std::cout << termcolor::red << "^ ";
                }
                else if (typeid(*event) == typeid(Chest)){
                    std::cout << termcolor::green << "$ ";
                }
                else if (typeid(*event) == typeid(Teleport)){
                    std::cout << termcolor::yellow << "% ";
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

void Renderer::terminal_clear() {
    system("clear");
}

void Renderer::print_menu(Menu& menu) {
    if (typeid(menu) == typeid(MainMenu))
        std::cout << "\n\t| DUNGEON CRAWLER |\n\n";

    else if (typeid(menu) == typeid(SettingsMenu))
        std::cout << "\n\t| SETTINGS |\n\n";

    else if (typeid(menu) == typeid(PauseMenu))
        std::cout << "\n\t| PAUSE |\n\n";

    else if (typeid(menu) == typeid(VictoryMenu))
        std::cout << "\n\t| VICTORY |\n\n";

    else if (typeid(menu) == typeid(DefeatMenu))
        std::cout << "\n\t| DEFEAT |\n\n";

    for (int i = 0; i < menu.options.size(); i++){
        std::cout << "\t";
        if (i == menu.curr_option) std::cout << "> ";
        std::cout << menu.options[i].first << std::endl;
    }
}

Renderer::Renderer() = default;

Renderer::~Renderer() = default;