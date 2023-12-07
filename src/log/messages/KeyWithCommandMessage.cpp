#include "KeyWithCommandMessage.h"

KeyWithCommandMessage::KeyWithCommandMessage(int key, std::string command): key(key), command(std::move(command)) {}

void KeyWithCommandMessage::print(std::ostream &stream) {
    stream << "Key pressed - key:\'" << (char)key << "\' command:" << command;
}
