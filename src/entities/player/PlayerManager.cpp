#include "PlayerManager.h"


void PlayerManager::take_damage(int taken_damage) {
    taken_damage = std::clamp(taken_damage, 0, max_health+max_armor);

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
    health_healed = std::clamp(health_healed, 0, max_health);

    player.set_health(player.get_health() + health_healed);
    if (player.get_health() > max_health){
        player.set_health(max_health);
    }
}

void PlayerManager::raise_shield() {
    player.set_armor(max_armor);
}

void PlayerManager::upgrade_weapon() {
    player.set_damage(player.get_damage() + 5);
    if (player.get_damage() > max_damage){
        player.set_damage(max_damage);
    }
}

void PlayerManager::pick_up_bombs(int bombs) {
    player.set_bombs(player.get_bombs() + bombs);
    if (player.get_bombs() > max_bombs){
        player.set_bombs(max_bombs);
    }
}

bool PlayerManager::is_defeated() const{
    return player.get_health() == 0;
}

bool PlayerManager::is_full_health() const {
    return player.get_health() == max_health;
}

bool PlayerManager::is_full_shield() const {
    return player.get_armor() == max_armor;
}

bool PlayerManager::is_fully_upgraded_weapon() const {
    return player.get_damage() == max_damage;
}

bool PlayerManager::is_full_bombs() const {
    return player.get_bombs() == max_bombs;
}

void PlayerManager::move(direction dir) {
    switch (dir) {
        case right:
        {
            if (position.first < playground.get_size().first - 1)
            {
                if (playground.get_cell_type({position.first + 1, position.second}) != obstacle){
                    position.first++;
                }
                else if (get_bombs() != 0){
                    position.first++;
                    perform_cell_event();
                    position.first--;
                }
            }
            break;
        }

        case down:
        {
            if (position.second < playground.get_size().second - 1)
            {
                if (playground.get_cell_type({position.first, position.second + 1}) != obstacle){
                    position.second++;
                }
                else if (get_bombs() != 0){
                    position.second++;
                    perform_cell_event();
                    position.second--;
                }
            }
            break;
        }

        case left:
        {
            if (position.first > 0)
            {
                if (playground.get_cell_type({position.first - 1, position.second}) != obstacle){
                    position.first--;
                }
                else if (get_bombs() != 0){
                    position.first--;
                    perform_cell_event();
                    position.first++;
                }
            }
            break;
        }

        case up:
        {
            if (position.second > 0)
            {
                if (playground.get_cell_type({position.first, position.second - 1}) != obstacle){
                    position.second--;
                }
                else if (get_bombs() != 0){
                    position.second--;
                    perform_cell_event();
                    position.second++;
                }
            }
            break;
        }

        case none:
            break;


    }

    perform_cell_event();
    notify();
}

void PlayerManager::perform_cell_event() {
    if (playground.get_cell_event(position) != nullptr){
        playground.get_cell_event(position)->perform(*this, playground);
    }
}

std::pair<int, int>& PlayerManager::get_position(){
    return position;
}

void PlayerManager::set_position(std::pair<int, int> position_){
    position = position_;
}


int PlayerManager::get_health() const{
    return player.get_health();
}

int PlayerManager::get_armor() const{
    return player.get_armor();
}

int PlayerManager::get_damage() const{
    return player.get_damage();
}

int PlayerManager::get_bombs() const {
    return player.get_bombs();
}

PlayerManager::PlayerManager(Player &player_, Playground& playground_): position({0, 0}), player(player_), playground(playground_), observer(
        nullptr), passed_levels(0) {}

bool PlayerManager::is_on_exit() const {
    return playground.get_cell_type(position) == exit_;
}

void PlayerManager::add_observer(IObserver *observer_) {
    observer = observer_;
}

void PlayerManager::notify() {
    observer->update(&playground);
    observer->update(this);
}

void PlayerManager::pass_level() {
    passed_levels += 1;
}

int PlayerManager::get_passed_levels() {
    return passed_levels;
}

void PlayerManager::reset_passed_levels() {
    passed_levels = 0;
}

PlayerManager::~PlayerManager() = default;