#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#define MAX_HEALTH 10
#define MAX_SHIELD 5
#define MAX_DAMAGE 20


class Player {
private:
    int health; // will be 10 at start
    int armor;  // will be 0 at start
    int damage; // will be 5 at start
    int money;  // will be 0 at start
public:
    Player();
    ~Player();

    int get_health() const;
    int get_armor() const;
    int get_damage() const;

    void set_health(int health_);
    void set_armor(int armor_);
    void set_damage(int damage_);

    //attack method requires an enemy instance
};


#endif //OOP_PLAYER_H
