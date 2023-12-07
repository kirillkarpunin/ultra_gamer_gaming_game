#include "ConsoleAppender.h"

ConsoleAppender::ConsoleAppender() = default;

void ConsoleAppender::append(Message &message) {
    std::cout << time() << message << "\n";
}