#include "Teleport.h"
#include "../../entities/player/PlayerManager.h"

void Teleport::perform(PlayerManager& player_manager, Playground& playground){
    if(player_manager.get_position() == playground.get_portals().get_position()){
        playground.get_portals().move_head();
    }

    player_manager.set_position(playground.get_portals().get_position());
    playground.get_portals().move_head();
}

Teleport::Teleport() = default;
Teleport::~Teleport() = default;
