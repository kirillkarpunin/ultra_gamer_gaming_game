#include "DefeatMessage.h"

DefeatMessage::DefeatMessage(std::pair<int, int> position): position(std::move(position)) {}

void DefeatMessage::print(std::ostream &stream) {
    stream << "Player defeated - x:" << position.first << " y:" << position.second;
}
