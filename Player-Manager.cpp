#include <algorithm>

#include "Player-Manager.h"


void PlayerManager::take_damage(int taken_damage) {
    taken_damage = std::clamp(taken_damage, 0, MAX_HEALTH+MAX_SHIELD);

    if (player.get_armor() >= taken_damage){
        player.set_armor(player.get_armor() - taken_damage);
    }
    else{
        player.set_health(player.get_health() - (taken_damage - player.get_armor()));
        player.set_armor(0);
    }

    if (player.get_health() < 0){
        player.set_health(0);
    }
}

void PlayerManager::use_bomb() {
    if (player.get_bombs()) {
        player.set_bombs(player.get_bombs() - 1);
    }
}

void PlayerManager::heal(int health_healed) {
    health_healed = std::clamp(health_healed, 0, MAX_HEALTH);

    player.set_health(player.get_health() + health_healed);
    if (player.get_health() > MAX_HEALTH){
        player.set_health(MAX_HEALTH);
    }
}

void PlayerManager::raise_shield() {
    player.set_armor(MAX_SHIELD);
}

void PlayerManager::upgrade_weapon() {
    player.set_damage(player.get_damage() + 5);
    if (player.get_damage() > MAX_DAMAGE){
        player.set_damage(MAX_DAMAGE);
    }

}

void PlayerManager::pick_up_bomb() {
    player.set_bombs(player.get_bombs() + 1);
    if (player.get_bombs() > MAX_BOMBS){
        player.set_bombs(MAX_BOMBS);
    }
}

bool PlayerManager::is_defeated() const{
    return player.get_health() == 0;
}

bool PlayerManager::is_full_health() const {
    return player.get_health() == MAX_HEALTH;
}

bool PlayerManager::is_full_shield() const {
    return player.get_armor() == MAX_SHIELD;
}

bool PlayerManager::is_fully_upgraded_weapon() const {
    return player.get_damage() == MAX_DAMAGE;
}

bool PlayerManager::is_full_bombs() const {
    return player.get_bombs() == MAX_BOMBS;
}

void PlayerManager::move(direction dir) {
    switch (dir) {
        case right:
        {
            if (position.first < playground.get_size().first - 1 &&
                playground.get_cell_type_by_coords({position.first + 1, position.second}) != obstacle)
            {
                playground.change_cell_type_by_coords(position, current_cell_type);
                position.first++;
                current_cell_type = playground.get_cell_type_by_coords(position);
                playground.change_cell_type_by_coords(position, player_);
            }
            break;
        }

        case down:
        {
            if (position.second < playground.get_size().second - 1 &&
                playground.get_cell_type_by_coords({position.first, position.second + 1}) != obstacle)
            {
                playground.change_cell_type_by_coords(position, current_cell_type);
                position.second++;
                current_cell_type = playground.get_cell_type_by_coords(position);
                playground.change_cell_type_by_coords(position, player_);
            }
            break;
        }

        case left:
        {
            if (position.first > 0 &&
                playground.get_cell_type_by_coords({position.first - 1, position.second}) != obstacle)
            {
                playground.change_cell_type_by_coords(position, current_cell_type);
                position.first--;
                current_cell_type = playground.get_cell_type_by_coords(position);
                playground.change_cell_type_by_coords(position, player_);
            }
            break;
        }

        case up:
        {
            if (position.second > 0 &&
                playground.get_cell_type_by_coords({position.first, position.second - 1}) != obstacle)
            {
                playground.change_cell_type_by_coords(position, current_cell_type);
                position.second--;
                current_cell_type = playground.get_cell_type_by_coords(position);
                playground.change_cell_type_by_coords(position, player_);
            }
            break;
        }
    }
    // position checks will be added later (obstacles, enemies, etc)
}


std::pair<int, int>& PlayerManager::get_position(){
    return position;
}

PlayerManager::PlayerManager(Player &player_, Playground& playground_): position({0, 0}), player(player_), playground(playground_), current_cell_type(entrance) {}

PlayerManager::~PlayerManager() = default;