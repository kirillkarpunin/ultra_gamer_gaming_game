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

void Player::set_health(int health_){
    health = health_;
}

void Player::set_armor(int armor_){
    armor = armor_;
}

void Player::set_damage(int damage_){
    damage = damage_;
}


//
Player::Player(): health(10), armor(0), damage(5), money(0){}
Player::~Player() = default;