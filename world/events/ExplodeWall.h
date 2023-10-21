#ifndef OOP_EXPLODEWALL_H
#define OOP_EXPLODEWALL_H


#include "IEvent.h"

class ExplodeWall: public IEvent {
public:
    ExplodeWall();
    ~ExplodeWall();

    void perform(PlayerManager& player_manager, Playground& playground) final;
};


#endif //OOP_EXPLODEWALL_H
