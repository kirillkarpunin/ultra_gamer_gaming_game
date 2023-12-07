#ifndef OOP_KEYWITHOUTCOMMANDMESSAGE_H
#define OOP_KEYWITHOUTCOMMANDMESSAGE_H

#include "Message.h"

class KeyWithoutCommandMessage: public Message {
private:
    int key;
public:
    KeyWithoutCommandMessage(int key);
    void print(std::ostream& stream) override;
};


#endif //OOP_KEYWITHOUTCOMMANDMESSAGE_H
