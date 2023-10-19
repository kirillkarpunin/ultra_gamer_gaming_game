#ifndef OOP_MAPGENERATOR_H
#define OOP_MAPGENERATOR_H

#define OBSTACLE_CHANCE 15

#include <random>
#include <ctime>
#include "Playground.h"

class MapGenerator {
private:
    Playground& playground;

public:
    MapGenerator(Playground& playground_);
    ~MapGenerator();

    void generate();
    void create_objects(cell_types type, int n);
};


#endif //OOP_MAPGENERATOR_H
