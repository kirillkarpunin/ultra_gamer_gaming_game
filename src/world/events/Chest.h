#ifndef OOP_CHEST_H
#define OOP_CHEST_H

#include <ctime>
#include "IEvent.h"

constexpr int potion_heal = 3;
constexpr int bombs_pack = 3;

class Chest : public IEvent {
public:
    Chest();
    ~Chest();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_CHEST_H
