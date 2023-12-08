#include "Renderer.h"

void Renderer::render_map(Playground& playground, PlayerManager& player_manager){
    std::cout << std::endl;

    std::cout << "Level: " << player_manager.get_passed_levels() << std::endl << std::endl;

    for (int i = 0; i < playground.get_size().second; i++)
    {
        for (int j = 0; j < playground.get_size().first; j++)
        {
            if (player_manager.get_position() == std::pair<int, int>{j,i}){
                std::cout << termcolor::magenta << "@ ";
            }

            else if (fog && (abs(player_manager.get_position().first - j) > fog_rad || abs(player_manager.get_position().second - i) > fog_rad )){
                std::cout << termcolor::grey << "~ ";
            }

            else if (playground.get_entrance_point() == (std::pair<int,int>){j,i}){
                std::cout << termcolor::cyan << "o ";
            }

            else if (playground.get_exit_point() == (std::pair<int,int>){j,i}){
                std::cout << termcolor::cyan << "x ";
            }

            else {
                IEvent* event = playground.get_cell_event({j,i});

                if (event == nullptr){
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

    std::cout << menu;
}

Renderer::Renderer() = default;

Renderer::~Renderer() = default;