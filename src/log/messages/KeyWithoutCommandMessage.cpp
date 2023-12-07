#include "KeyWithoutCommandMessage.h"

KeyWithoutCommandMessage::KeyWithoutCommandMessage(int key): key(key) {}

void KeyWithoutCommandMessage::print(std::ostream &stream) {
    stream << "Pressed key - key:\'" << (char)key << "\' command:none";
}


