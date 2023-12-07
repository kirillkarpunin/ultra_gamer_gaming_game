#include "NewGameMessage.h"

NewGameMessage::NewGameMessage() = default;

void NewGameMessage::print(std::ostream &stream) {
    stream << "New game started";
}