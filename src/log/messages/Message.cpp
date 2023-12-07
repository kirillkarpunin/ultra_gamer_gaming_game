#include "Message.h"

std::ostream &operator<<(std::ostream &stream, Message& message) {
    message.print(stream);
    return stream;
}

Message::~Message() = default;
