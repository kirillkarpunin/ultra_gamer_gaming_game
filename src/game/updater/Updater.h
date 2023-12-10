#ifndef OOP_UPDATER_H
#define OOP_UPDATER_H

#include <queue>
#include <typeinfo>

#include "../../input_output/Renderer.h"
#include "../../sup/observer/IObserver.h"
#include "../../world/map/Playground.h"
#include "../../entities/player/PlayerManager.h"
#include "../../log/Logger.h"

class Updater: public IObserver{
private:
    Renderer* renderer;
    Logger* logger;
    std::queue<IObservable*> update_q;
    std::queue<Message*> message_q;
public:
    Updater();
    ~Updater();

    void update_game_frame(Playground* playground, PlayerManager* player_manager);
    void update_menu_frame(Menu* menu);

    void add_to_logger(Appender* appender);
    void add_message(Message* message);
    void update_logs();

    void update(IObservable* observable_element) override;
    void check_updates();
};


#endif //OOP_UPDATER_H
