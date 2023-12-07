#ifndef OOP_VICTORYMESSAGE_H
#define OOP_VICTORYMESSAGE_H

#include "Message.h"

class VictoryMessage: public Message{
private:
    int health;
    int armor;
    int damage;
    int bombs;
public:
    VictoryMessage(int health, int armor, int damage, int bombs);
    void print(std::ostream& stream) override;
};


#endif //OOP_VICTORYMESSAGE_H
