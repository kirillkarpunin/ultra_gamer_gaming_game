#include "MapGenerator.h"

void MapGenerator::create_objects(cell_types type, int n){
    for (int i = 0; i < n; i++)
    {
        int x_ = rand() % playground.get_size().first;
        int y_ = rand() % playground.get_size().second;
        if (playground.get_cell_type({x_, y_}) != empty){
            i--;
            continue;
        }
        else {
            playground.set_cell_type({x_, y_}, type);
        }
    }
}

void MapGenerator::generate(){
    playground.set_cell_type(playground.get_entrance_point(), entrance);
    playground.set_cell_type(playground.get_exit_point(), exit_);

    srand(clock());

    int first_path = rand() % 2;
    int second_path = !first_path;

    for (int i = 1 * first_path; i < playground.get_size().second - 1 * second_path; i++)
    {
        for (int j = 1 * second_path; j < playground.get_size().first - 1 * first_path; j++)
        {
            if (playground.get_cell_type({j,i}) == empty)
            {
                if ( rand() % 100 + 1 > (100 - OBSTACLE_CHANCE) )
                {
                    playground.set_cell_type({j,i}, obstacle);
                }
            }
        }
    }

    create_objects(trap, (int)sqrt(playground.get_size().first * playground.get_size().second) / 4);
    create_objects(chest, (int)sqrt(playground.get_size().first * playground.get_size().second) / 8);
    create_objects(portal, 2);
}

MapGenerator::MapGenerator(Playground& playground_): playground(playground_) {}

MapGenerator::~MapGenerator() = default;
