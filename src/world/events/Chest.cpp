#include "Chest.h"
#include "../../entities/player/PlayerManager.h"

enum goods {potion, shield, bombs, grindstone};

void Chest::perform(PlayerManager &player_manager, Playground& playground) {
    goods chest[4];
    int n = 0;

    if (!player_manager.is_full_health()){
        chest[n++] = potion;
    }
    if (!player_manager.is_full_shield()){
        chest[n++] = shield;
    }
    if (!player_manager.is_fully_upgraded_weapon()){
        chest[n++] = grindstone;
    }
    if (!player_manager.is_full_bombs()){
        chest[n++] = bombs;
    }

    if (n == 0) return;

    srand(clock());
    goods item = chest[rand() % n];

    switch (item) {
        case potion:
            player_manager.heal(potion_heal);
            break;
        case shield:
            player_manager.raise_shield();
            break;
        case grindstone:
            player_manager.upgrade_weapon();
            break;
        case bombs:
            player_manager.pick_up_bombs(bombs_pack);
            break;
    }

    playground.set_cell_type(player_manager.get_position(), empty);
}

Chest::Chest() = default;
Chest::~Chest() = default;
