#ifndef OOP_NEWLEVELMESSAGE_H
#define OOP_NEWLEVELMESSAGE_H

#include "Message.h"

class NewLevelMessage: public Message {
private:
    std::pair<int, int> size;
    std::pair<int, int> position;
    int level_n;
public:
    NewLevelMessage(std::pair<int, int> size, std::pair<int, int> position, int level_n);
    void print(std::ostream& stream) override;
};


#endif //OOP_NEWLEVELMESSAGE_H
