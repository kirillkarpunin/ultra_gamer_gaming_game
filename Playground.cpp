#include <algorithm>
#include <ctime>
#include <iostream>
#include <cmath>

#include "Playground.h"

#define OBSTACLE_CHANCE 15

void Playground::create_objects_on_map(cell_types type, int n){
    for (int i = 0; i < n; i++)
    {
        int x_ = rand() % playground_size.first;
        int y_ = rand() % playground_size.second;
        if (map[y_][x_].get_cell_type() != empty){
            i--;
            continue;
        }
        else {
            map[y_][x_].set_cell_type(type);
        }
    }
}

void Playground::create_map(){
    map[entrance_point.second][entrance_point.first].set_cell_type(player_);
    map[exit_point.second][exit_point.first].set_cell_type(exit_);

    srand(clock());

    int first_path = rand() % 2;
    int second_path = !first_path;

    for (int i = 1 * first_path; i < playground_size.second - 1 * second_path; i++)
    {
        for (int j = 1 * second_path; j < playground_size.first - 1 * first_path; j++)
        {
            if (map[i][j].get_cell_type() == empty)
            {
                if ( rand() % 100 + 1 > (100 - OBSTACLE_CHANCE) )
                {
                    map[i][j].set_cell_type(obstacle);
                }
            }
        }
    }

    create_objects_on_map(trap, (int)sqrt(playground_size.first * playground_size.second) / 4);
    create_objects_on_map(chest, (int)sqrt(playground_size.first * playground_size.second) / 4);
}

void Playground::print_map() const{
    for (int i = 0; i < playground_size.second; i++)
    {
        for (int j = 0; j < playground_size.first; j++)
        {
            switch (map[i][j].get_cell_type())
            {
                case empty: {
                    std::cout << ". ";
                    break;
                }
                case obstacle: {
                    std::cout << "# ";
                    break;
                }
                case trap: {
                    std::cout << "^ ";
                    break;
                }
                case chest: {
                    std::cout << "$ ";
                    break;
                }
                case entrance: {
                    std::cout << "o ";
                    break;
                }
                case exit_: {
                    std::cout << "x ";
                    break;
                }
                case player_: {
                    std::cout << "@ ";
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
}

cell_types Playground::get_cell_type_by_coords(std::pair<int, int> coords){
    return map[coords.second][coords.first].get_cell_type();
}

void Playground::change_cell_type_by_coords(std::pair<int, int> coords, cell_types type) {
    map[coords.second][coords.first].set_cell_type(type);
}

std::pair<int, int>& Playground::get_size(){
    return playground_size;
}

Playground::Playground(int width, int height) {
    width = std::clamp(width, 4, 64);
    height = std::clamp(height, 4, 64);

    playground_size = {width, height};

    entrance_point = {0, 0};
    exit_point = {playground_size.first - 1, playground_size.second - 1};

    map = new Cell* [playground_size.second];
    for (int i = 0; i < playground_size.second; i++){
        map[i] = new Cell [playground_size.first];
    }

    create_map();
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