#ifndef OOP_MESSAGE_H
#define OOP_MESSAGE_H

#include <ostream>

class Message {
protected:
    virtual void print(std::ostream& stream) = 0;
public:
    friend std::ostream& operator<< (std::ostream& stream, Message& message);

    virtual ~Message();
};


#endif //OOP_MESSAGE_H
