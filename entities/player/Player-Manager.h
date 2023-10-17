#ifndef OOP_PLAYER_MANAGER_H
#define OOP_PLAYER_MANAGER_H

#include <utility>

#include "Player.h"
#include "../../world/Playground.h"


enum direction {right, down, left, up};

class PlayerManager {
private:
    std::pair<int, int> position;
    Player& player;
    Playground& playground;
public:
    PlayerManager(Player& player_, Playground& playground_);
    ~PlayerManager();

    void take_damage(int taken_damage);
    void use_bomb();

    void heal(int health_healed);
    void raise_shield();
    void upgrade_weapon();
    void pick_up_bomb();

    bool is_defeated() const;

    bool is_full_shield() const;
    bool is_fully_upgraded_weapon() const;
    bool is_full_health() const;
    bool is_full_bombs() const;

    void move(direction dir);

    std::pair<int, int>& get_position();
};


#endif //OOP_PLAYER_MANAGER_H
