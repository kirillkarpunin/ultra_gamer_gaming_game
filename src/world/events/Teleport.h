#ifndef OOP_TELEPORT_H
#define OOP_TELEPORT_H

#include "IEvent.h"


class Teleport: public IEvent {
public:
    Teleport();
    ~Teleport();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_TELEPORT_H
