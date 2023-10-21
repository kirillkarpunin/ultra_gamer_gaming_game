#ifndef OOP_CHEST_H
#define OOP_CHEST_H

#define POTION_HEAL 3
#define BOMBS 3

#include <ctime>

#include "IEvent.h"

class Chest : public IEvent {
public:
    Chest();
    ~Chest();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_CHEST_H
