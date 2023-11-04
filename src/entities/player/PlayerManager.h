#ifndef OOP_PLAYERMANAGER_H
#define OOP_PLAYERMANAGER_H

#include <utility>
#include <algorithm>

#include "Player.h"
#include "../../world/map/Playground.h"

enum direction {right, down, left, up, none};

class PlayerManager {
private:
    std::pair<int, int> position;
    Player& player;
    Playground& playground;
public:
    PlayerManager(Player& player_, Playground& playground_);
    ~PlayerManager();

    void take_damage(int taken_damage);
    void heal(int health_healed);

    void raise_shield();

    void upgrade_weapon();

    void use_bomb();
    void pick_up_bombs(int bombs);

    bool is_defeated() const;
    bool is_on_exit() const;

    bool is_full_shield() const;
    bool is_fully_upgraded_weapon() const;
    bool is_full_health() const;
    bool is_full_bombs() const;

    int get_health() const;
    int get_armor() const;
    int get_damage() const;
    int get_bombs() const;

    void move(direction dir);
    void perform_cell_event();

    std::pair<int, int>& get_position();
    void set_position(std::pair<int, int> position_);
};


#endif //OOP_PLAYERMANAGER_H
