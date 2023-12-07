#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H

#include "appenders/FileAppender.h"
#include "appenders/ConsoleAppender.h"

#include "messages/VictoryMessage.h"
#include "messages/DefeatMessage.h"
#include "messages/NewLevelMessage.h"
#include "messages/NewGameMessage.h"
#include "messages/KeyWithCommandMessage.h"
#include "messages/KeyWithoutCommandMessage.h"

#include <vector>

class Logger {
private:
    std::vector<Appender*> appenders;
public:
    Logger() = default;
    void add_appender(Appender* appender);
    void log(Message& message);
    ~Logger();
};


#endif //OOP_LOGGER_H
