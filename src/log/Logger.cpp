#include "Logger.h"

void Logger::add_appender(Appender* appender) {
    appenders.push_back(appender);
}

Logger::~Logger() {
    for (auto elem : appenders){
        delete elem;
    }
}

Logger::Logger() = default;

void Logger::log(Message& message) {
    for (auto elem : appenders){
        elem->append(message);
    }
}


