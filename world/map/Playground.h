#pragma once

#ifndef OOP_PLAYGROUND_H
#define OOP_PLAYGROUND_H

#define MIN_MAP_WIDTH 10
#define DEF_MAP_WIDTH 30
#define MAX_MAP_WIDTH 64

#define MIN_MAP_HEIGHT 10
#define DEF_MAP_HEIGHT 15
#define MAX_MAP_HEIGHT 64


class Playground;
#include <utility>
#include "Cell.h"


class Playground {
private:
    std::pair<int, int> playground_size;
    Cell** map;

    std::pair<int, int> entrance_point;
    std::pair<int, int> exit_point;

public:
    Playground(int width = DEF_MAP_WIDTH, int height = DEF_MAP_HEIGHT);
    ~Playground();

    Playground(const Playground& playground);
    Playground& operator = (const Playground& playground);

    Playground(Playground&& playground);
    Playground& operator = (Playground&& playground);

    cell_types get_cell_type(std::pair<int, int> position);
    IEvent* get_cell_event(std::pair<int, int> position);

    void set_cell_type(std::pair<int, int> position, cell_types type);
    std::pair<int, int> get_size();

    std::pair<int, int> get_entrance_point();
    std::pair<int, int> get_exit_point();
};


#endif //OOP_PLAYGROUND_H
