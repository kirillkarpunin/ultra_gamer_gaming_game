#ifndef OOP_KEYWITHCOMMANDMESSAGE_H
#define OOP_KEYWITHCOMMANDMESSAGE_H

#include "Message.h"
#include <utility>

class KeyWithCommandMessage: public Message {
private:
    int key;
    std::string command;
public:
    KeyWithCommandMessage(int key, std::string command);
    void print(std::ostream& stream) override;
};


#endif //OOP_KEYWITHCOMMANDMESSAGE_H
