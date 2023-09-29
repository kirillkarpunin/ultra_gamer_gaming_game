#include "Player.h"


int Player::get_health() const{
    return health;
}

int Player::get_armor() const{
    return armor;
}

int Player::get_damage() const{
    return damage;
}

int Player::get_bombs() const {
    return bombs;
}

void Player::set_health(int health_){
    health = health_;
}

void Player::set_armor(int armor_){
    armor = armor_;
}

void Player::set_damage(int damage_){
    damage = damage_;
}

void Player::set_bombs(int bombs_) {
    bombs = bombs_;
}

Player::Player(): health(10), armor(0), damage(5), bombs(1){}

Player::~Player() = default;