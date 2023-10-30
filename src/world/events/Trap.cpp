#include "Trap.h"
#include "../../entities/player/PlayerManager.h"

void Trap::perform(PlayerManager& player_manager, Playground& playground) {
    player_manager.take_damage(trap_damage);
}

Trap::Trap() = default;
Trap::~Trap() = default;
