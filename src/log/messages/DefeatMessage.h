#ifndef OOP_DEFEATMESSAGE_H
#define OOP_DEFEATMESSAGE_H

#include "Message.h"

class DefeatMessage: public Message {
private:
    std::pair<int, int> position;
public:
    DefeatMessage(std::pair<int,int> position);
    void print(std::ostream& stream) override;
};


#endif //OOP_DEFEATMESSAGE_H
