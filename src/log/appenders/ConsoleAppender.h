#ifndef OOP_CONSOLEAPPENDER_H
#define OOP_CONSOLEAPPENDER_H

#include <iostream>

#include "Appender.h"

class ConsoleAppender: public Appender {
public:
    ConsoleAppender();
    void append(Message &message) override;
};


#endif //OOP_CONSOLEAPPENDER_H
