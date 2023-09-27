#ifndef OOP_PLAYER_MANAGER_H
#define OOP_PLAYER_MANAGER_H

#include <utility>
#include "Player.h"


enum direction {right, down, left, up};

class PlayerManager {
private:
    std::pair<int, int> position;
    Player& player;
    // this class will get an instance of 'playground' class, so it will get access to every cell of the field and to size of the field
public:
    explicit PlayerManager(Player& player_);
    ~PlayerManager();

    void take_damage(int taken_damage);

    void heal(int health_healed);
    void raise_shield();
    void upgrade_weapon();

    bool is_defeated() const;

    void move(direction dir);

    std::pair<int, int> get_position() const;
};


#endif //OOP_PLAYER_MANAGER_H
