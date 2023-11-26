#include "MenuHandler.h"
#include "../Game.h"

MenuHandler::MenuHandler() = default;
MenuHandler::~MenuHandler() = default;

menu_options MenuHandler::run_menu(Game* game, Menu* menu) {
    menu->create_options();

    game->renderer->terminal_clear();
    game->renderer->print_menu(*menu);

    while (menu->is_active()){

        switch (game->input_handler->get_key()) {
            case esc_key:
                menu->close();
                return resume;
            case up_key:
                menu->option_up();
                game->renderer->terminal_clear();
                game->renderer->print_menu(*menu);
                break;
            case down_key:
                menu->option_down();
                game->renderer->terminal_clear();
                game->renderer->print_menu(*menu);
                break;
            case wait_key:
                menu->close();
                return menu->choose_option();
            default:
                break;
        }
    }
}
