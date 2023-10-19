#pragma once

#ifndef OOP_IEVENT_H
#define OOP_IEVENT_H

class IEvent;
#include "../../entities/player/Player-Manager.h"


class IEvent {
public:
    virtual void perform(PlayerManager& player_manager) = 0;
    virtual ~IEvent() {};
};
//IEvent::~IEvent() {}


#endif //OOP_IEVENT_H
