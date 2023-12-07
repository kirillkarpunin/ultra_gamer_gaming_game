#include "VictoryMessage.h"

VictoryMessage::VictoryMessage(int health, int armor, int damage, int bombs): health(health), armor(armor), damage(damage), bombs(bombs) {}

void VictoryMessage::print(std::ostream &stream) {
    stream << "Player won - health:" << health << " armor:" << armor << " damage:" << damage << " bombs:" << bombs;
}


