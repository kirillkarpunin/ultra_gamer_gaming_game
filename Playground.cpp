#include <algorithm>
#include <ctime>
#include <iostream>
#include <cmath>

#include "Playground.h"

#define OBSTACLE_CHANCE 10


void Playground::create_map() {
    map = new Cell* [playground_size.second];
    for (int i = 0; i < playground_size.second; i++){
        map[i] = new Cell [playground_size.first];
    }

    map[entrance_point.second][entrance_point.first].set_cell_type(entrance);
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

    for (int i = 0; i < sqrt(playground_size.first * playground_size.second) / 2; i++)
    {
        int x_ = rand() % playground_size.first;
        int y_ = rand() % playground_size.second;
        if (map[y_][x_].get_cell_type() != empty){
            i--;
            continue;
        }
        else {
            map[y_][x_].set_cell_type(trap);
        }
    }
}

void Playground::print_map() {
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
                case entrance: {
                    std::cout << "o ";
                    break;
                }
                case exit_: {
                    std::cout << "x ";
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
}

cell_types Playground::get_cell_type_by_coords(int x, int y){
    return map[y][x].get_cell_type();
}

std::pair<int, int>& Playground::get_size(){
    return playground_size;
}

Playground::Playground(int width, int height) {
    width = std::clamp(width, 4, 64);
    height = std::clamp(height, 4, 64);

    playground_size.first = width;
    playground_size.second = height;

    entrance_point = {0, 0};
    exit_point = {playground_size.first - 1, playground_size.second - 1};

    create_map();
}

Playground::~Playground() {
    for (int i = 0; i < playground_size.second; i++){
        delete [] map[i];
    }
    delete [] map;
}