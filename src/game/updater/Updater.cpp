#include "Updater.h"

void Updater::update(IObservable * observable_element) {
    update_q.push(observable_element);
}

void Updater::check_updates() {
    if (!update_q.empty())
    {
        IObservable* elem = update_q.front();

        if (typeid(*elem) == typeid(Playground))
        {
            auto* playground = dynamic_cast<Playground *>(elem);
            update_q.pop();
            auto* player_manager = dynamic_cast<PlayerManager *>(update_q.front());
            update_q.pop();

            update_game_frame(playground, player_manager);
        }

        else if (dynamic_cast<Menu*>(elem) != nullptr)
        {
            auto* menu = dynamic_cast<Menu*>(elem);
            update_q.pop();

            update_menu_frame(menu);
        }
    }
    update_logs();
}

Updater::Updater() {
    renderer = new Renderer();
    logger = new Logger();
}

Updater::~Updater() {
    delete renderer;
    delete logger;
}

void Updater::update_game_frame(Playground *playground, PlayerManager *player_manager) {
    renderer->terminal_clear();
    renderer->render_map(*playground, *player_manager);
    renderer->print_player_info(*player_manager);
}

void Updater::update_menu_frame(Menu *menu) {
    renderer->terminal_clear();
    renderer->print_menu(*menu);
}

void Updater::add_message(Message* message) {
    message_q.push(message);
}

void Updater::update_logs() {
    while (!message_q.empty()){
        Message* message = message_q.front();
        message_q.pop();
        logger->log(*message);
        delete message;
    }
}

void Updater::add_to_logger(Appender* appender) {
    logger->add_appender(appender);
}
