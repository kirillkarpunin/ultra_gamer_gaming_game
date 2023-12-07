#include "Appender.h"

std::string Appender::time() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::stringstream ss;
    ss << std::put_time(&tm, "[%d.%m.%Y %H:%M:%S] ");
    return ss.str();
}

Appender::~Appender() = default;
