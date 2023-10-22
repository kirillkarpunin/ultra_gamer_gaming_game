#ifndef OOP_IEVENT_H
#define OOP_IEVENT_H

class PlayerManager;
class Playground;

class IEvent {
public:
    virtual void perform(PlayerManager& player_manager, Playground& playground) = 0;

    virtual ~IEvent() = default;
};


#endif //OOP_IEVENT_H
