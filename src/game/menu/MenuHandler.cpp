#include "MenuHandler.h"
#include "../Game.h"

MenuHandler::MenuHandler() {
    observer = nullptr;
}
MenuHandler::~MenuHandler() = default;

menu_options MenuHandler::run_menu(Game* game, Menu* menu) {
    menu->create_options();
    menu->add_observer(observer);

    game->updater->update_menu_frame(menu);

    while (true){
        switch (game->input_handler->get_key()) {
            case up_key:
                menu->option_up();
                break;
            case down_key:
                menu->option_down();
                break;
            case wait_key:
                return menu->choose_option();
            case esc_key:
                return resume;
            default:
                break;
        }

        game->updater->check_updates();
    }
}

void MenuHandler::set_observer(IObserver *observer_) {
    observer = observer_;
}
