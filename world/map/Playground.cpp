#include <algorithm>
#include <iostream>

#include "Playground.h"

cell_types Playground::get_cell_type(std::pair<int, int> position){
    int x = std::clamp(position.first, 0, playground_size.first-1);
    int y = std::clamp(position.second, 0, playground_size.second-1);

    return map[y][x].get_type();
}

void Playground::set_cell_type(std::pair<int, int> position, cell_types type) {
    int x = std::clamp(position.first, 0, playground_size.first-1);
    int y = std::clamp(position.second, 0, playground_size.second-1);

    map[y][x].set_type(type);
}

std::pair<int, int> Playground::get_size(){
    return playground_size;
}

std::pair<int, int> Playground::get_entrance_point() {
    return entrance_point;
}

std::pair<int, int> Playground::get_exit_point() {
    return exit_point;
}

Playground::Playground(int width, int height) {
    width = std::clamp(width, MIN_MAP_WIDTH, MAX_MAP_WIDTH);
    height = std::clamp(height, MIN_MAP_HEIGHT, MAX_MAP_HEIGHT);

    playground_size = {width, height};

    entrance_point = {0, 0};
    exit_point = {playground_size.first - 1, playground_size.second - 1};

    map = new Cell* [playground_size.second];
    for (int i = 0; i < playground_size.second; i++){
        map[i] = new Cell [playground_size.first];
    }
}

Playground::~Playground() {
    for (int i = 0; i < playground_size.second; i++){
        delete [] map[i];
    }
    delete [] map;
}

Playground::Playground(const Playground& playground) {
    playground_size = playground.playground_size;

    entrance_point = playground.entrance_point;
    exit_point = playground.exit_point;

    map = new Cell* [playground_size.second];
    for (int i = 0; i < playground_size.second; i++){
        map[i] = new Cell [playground_size.first];
    }

    for (int i = 0; i < playground_size.second; i++){
        std::copy(playground.map[i], playground.map[i] + playground_size.first, map[i]);
    }
}

Playground& Playground::operator = (const Playground& playground) {
    Playground tmp(playground);

    std::swap(playground_size, tmp.playground_size);
    std::swap(entrance_point, tmp.entrance_point);
    std::swap(exit_point, tmp.exit_point);
    std::swap(map, tmp.map);

    return *this;
}

Playground::Playground(Playground &&playground) {
    playground_size = {0, 0};
    entrance_point = {0, 0};
    exit_point = {0, 0};
    map = nullptr;

    std::swap(playground_size, playground.playground_size);
    std::swap(entrance_point, playground.entrance_point);
    std::swap(exit_point, playground.exit_point);
    std::swap(map, playground.map);
}

Playground& Playground::operator = (Playground&& playground) {
    if (this != &playground){
        std::swap(playground_size, playground.playground_size);
        std::swap(entrance_point, playground.entrance_point);
        std::swap(exit_point, playground.exit_point);
        std::swap(map, playground.map);
    }
    return *this;
}