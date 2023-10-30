#ifndef OOP_TRAP_H
#define OOP_TRAP_H

#include "IEvent.h"

constexpr int trap_damage = 1;

class Trap: public IEvent {
public:
    Trap();
    ~Trap();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_TRAP_H
