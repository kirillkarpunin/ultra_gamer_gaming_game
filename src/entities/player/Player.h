#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

constexpr int max_health = 10;
constexpr int max_armor = 5;
constexpr int max_damage = 20;
constexpr int max_bombs = 5;

class Player {
private:
    int health;
    int armor;
    int damage;
    int bombs;
public:
    Player();
    ~Player();

    int get_health() const;
    int get_armor() const;
    int get_damage() const;
    int get_bombs() const;

    void set_health(int health_);
    void set_armor(int armor_);
    void set_damage(int damage_);
    void set_bombs(int bombs_);
};


#endif //OOP_PLAYER_H
