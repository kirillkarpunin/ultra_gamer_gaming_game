#ifndef OOP_PLAYERMANAGER_H
#define OOP_PLAYERMANAGER_H

#include <utility>
#include <algorithm>
#include <string>

#include "Player.h"
#include "../../world/map/Playground.h"

enum direction {right, down, left, up, none};

class PlayerManager: public IObservable{
private:
    std::pair<int, int> position;
    Player& player;
    Playground& playground;

    IObserver* observer;
    int passed_levels;
public:
    PlayerManager(Player& player_, Playground& playground_);
    ~PlayerManager() override;

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

    void add_observer(IObserver* observer_) override;
    void notify() override;

    void pass_level();
    int get_passed_levels();
    void reset_passed_levels();

    std::string dir_to_str(direction d);
};


#endif //OOP_PLAYERMANAGER_H
