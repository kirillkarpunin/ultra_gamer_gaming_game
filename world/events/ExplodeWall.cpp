#include "ExplodeWall.h"
#include "../../entities/player/PlayerManager.h"

void ExplodeWall::perform(PlayerManager &player_manager, Playground &playground) {
    player_manager.use_bomb();
    playground.set_cell_type(player_manager.get_position(), empty);
}

ExplodeWall::ExplodeWall() = default;
ExplodeWall::~ExplodeWall() = default;
