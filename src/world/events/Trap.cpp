#include "Trap.h"
#include "../../entities/player/PlayerManager.h"

void Trap::perform(PlayerManager& player_manager, Playground& playground) {
    player_manager.take_damage(TRAP_DAMAGE);
}

Trap::Trap() = default;
Trap::~Trap() = default;
