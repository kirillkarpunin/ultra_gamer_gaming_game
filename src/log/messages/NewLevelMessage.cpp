#include "NewLevelMessage.h"

NewLevelMessage::NewLevelMessage(std::pair<int, int> size, std::pair<int, int> position, int level_n): size(std::move(size)), position(std::move(position)), level_n(level_n) {}

void NewLevelMessage::print(std::ostream &stream) {
    stream << "Level " << level_n << " started - height:" << size.first << " width:" << size.second << " x:" << position.second << " y:" << position.first;
}
