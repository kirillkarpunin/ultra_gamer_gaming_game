#ifndef OOP_NEWGAMEMESSAGE_H
#define OOP_NEWGAMEMESSAGE_H

#include "Message.h"

class NewGameMessage: public Message {
public:
    NewGameMessage();
    void print(std::ostream& stream) override;
};


#endif //OOP_NEWGAMEMESSAGE_H
