#include "Updater.h"

Updater::Updater(Renderer* renderer_, Printer* printer_, Level* level_): level(level_), renderer(renderer_), printer(printer_) {}

void Updater::check_movement() {

    // message to logger

    IEvent* cell_event = level->playground->get_cell_event(level->player_manager->get_position());
    if (cell_event){
        check_cell_event(cell_event);
    }

    update_frame();
}

void Updater::check_cell_event(IEvent* cell_event) {
    if (typeid(*cell_event) == typeid(Trap)){
        // trap message
        // taken damage
        return;
    }

    if (typeid(*cell_event) == typeid(Chest)){
        // chest message
        // obtained what
        return;
    }

    if (typeid(*cell_event) == typeid(Teleport)){
        // teleport message
        // teleported where
        return;
    }

    if (typeid(*cell_event) == typeid(ExplodeWall)){
        // explosion message
        // will be in player's logs
        return;
    }

    // empty cell message
}

bool Updater::defeat() {
    bool ret = level->player_manager->is_defeated();
    if (ret){}
        // defeat message
    return ret;
}

bool Updater::victory() {
    bool ret = level->player_manager->is_on_exit();
    if (ret){}
        // victory message
    return ret;
}

Updater::~Updater() = default;

void Updater::update_frame() {
    renderer->terminal_clear();
    renderer->render_map(*level->playground, *level->player_manager);
    renderer->print_player_info(*level->player_manager);
}

void Updater::update_menu(Menu *menu) {
    renderer->print_menu(*menu);
}




