#include "Player-Manager.h"

void PlayerManager::take_damage(int taken_damage) {
    if (taken_damage > MAX_HEALTH+MAX_SHIELD){
        taken_damage = MAX_HEALTH+MAX_SHIELD;
    }
    if (taken_damage < 0){
        taken_damage = 0;
    }

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

void PlayerManager::heal(int health_healed) {
    if (health_healed > MAX_HEALTH){
        health_healed = MAX_HEALTH;
    }
    if (health_healed < 0){
        health_healed = 0;
    }

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

bool PlayerManager::is_defeated() const{
    return player.get_health() == 0;
}

void PlayerManager::move(direction dir) {
    switch (dir) {
        case right:
        {
            position.first++;
            break;
        }

        case down:
        {
            position.second++;
            break;
        }

        case left:
        {
            if (position.first > 0){
                position.first--;
            }
            break;
        }

        case up:
        {
            if (position.second > 0){
                position.second--;
            }
            break;
        }
    }
    // position checks will be added later (obstacles, enemies, etc)
}


std::pair<int, int> PlayerManager::get_position() const{
    return position;
}


//
PlayerManager::PlayerManager(Player &player_): position({0, 0}), player(player_){}
PlayerManager::~PlayerManager() = default;