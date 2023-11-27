#ifndef OOP_MAPGENERATOR_H
#define OOP_MAPGENERATOR_H

#include <random>
#include <ctime>
#include <algorithm>
#include "Playground.h"

constexpr int obstacle_chance = 37;

class MapGenerator {
private:
    void create_path(Playground& playground);
    void create_objects(Playground& playground, cell_types type, int n);
public:
    MapGenerator();
    ~MapGenerator();

    void generate(Playground& playground);
};


#endif //OOP_MAPGENERATOR_H
