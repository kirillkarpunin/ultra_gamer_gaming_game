#ifndef OOP_UPDATER_H
#define OOP_UPDATER_H

#include <queue>
#include <typeinfo>

#include "../../input_output/Renderer.h"
#include "../../sup/observer/IObserver.h"
#include "../../world/map/Playground.h"
#include "../../entities/player/PlayerManager.h"

class Updater: public IObserver{
private:
    Renderer* renderer;
    std::queue<IObservable*> update_q;
public:
    Updater();
    ~Updater();

    void update_game_frame(Playground* playground, PlayerManager* player_manager);
    void update_menu_frame(Menu* menu);

    void update(IObservable* observable_element) override;
    void check_updates();
};


#endif //OOP_UPDATER_H
