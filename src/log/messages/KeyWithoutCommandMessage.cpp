#include "KeyWithoutCommandMessage.h"

KeyWithoutCommandMessage::KeyWithoutCommandMessage(int key): key(key) {}

void KeyWithoutCommandMessage::print(std::ostream &stream) {
    stream << "Key pressed - key:\'" << (char)key << "\' no command";
}


