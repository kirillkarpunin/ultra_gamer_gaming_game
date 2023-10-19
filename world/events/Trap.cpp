#include "Trap.h"

void Trap::perform(PlayerManager& player_manager) {
    player_manager.take_damage(TRAP_DAMAGE);
}

Trap::Trap() = default;
Trap::~Trap() = default;
