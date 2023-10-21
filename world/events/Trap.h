#ifndef OOP_TRAP_H
#define OOP_TRAP_H

#define TRAP_DAMAGE 1

#include "IEvent.h"

class Trap: public IEvent {
public:
    Trap();
    ~Trap();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_TRAP_H
