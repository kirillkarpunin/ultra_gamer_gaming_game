#ifndef OOP_APPENDER_H
#define OOP_APPENDER_H

#include <ctime>
#include <iomanip>

#include "../messages/Message.h"

class Appender {
protected:
    std::string time();
public:
    virtual void append(Message& message) = 0;
    virtual ~Appender();
};


#endif //OOP_APPENDER_H
