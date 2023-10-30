#ifndef OOP_MAPGENERATOR_H
#define OOP_MAPGENERATOR_H

#include <random>
#include <ctime>
#include <algorithm>
#include "Playground.h"

constexpr int obstacle_chance = 35;

class MapGenerator {
private:
    Playground& playground;

    void create_path();
    void create_objects(cell_types type, int n);
public:
    MapGenerator(Playground& playground_);
    ~MapGenerator();

    void generate();
};


#endif //OOP_MAPGENERATOR_H
