#include "MapGenerator.h"

void MapGenerator::create_objects(cell_types type, int n){
    n = std::clamp(n, 0, (int)sqrt(playground.get_size().first * playground.get_size().second) / 2);

    for (int i = 0; i < n; i++)
    {
        int x_ = rand() % playground.get_size().first;
        int y_ = rand() % playground.get_size().second;
        if (playground.get_cell_type({x_, y_}) != empty){
            i--;
            continue;
        }
        else {
            if (type == portal){
                playground.get_portals().add({x_,y_});
            }
            playground.set_cell_type({x_, y_}, type);
        }
    }
}

void MapGenerator::create_path(){
    int x = 0;
    int y = 0;
    srand(clock());

    int r;
    while (x < playground.get_size().first || y < playground.get_size().second){
        r = rand() % playground.get_size().first;
        for (int i = 0; i < r; i++)
        {
            if (playground.get_cell_type({x,y}) == obstacle){
                playground.set_cell_type({x,y}, empty);
            }
            x++;
        }
        r = rand() % playground.get_size().second;
        for (int i = 0; i < r; i++)
        {
            if (playground.get_cell_type({x,y}) == obstacle){
                playground.set_cell_type({x,y}, empty);
            }
            y++;
        }
    }
}

void MapGenerator::generate(){
    playground.set_cell_type(playground.get_entrance_point(), entrance);
    playground.set_cell_type(playground.get_exit_point(), exit_);

    srand(clock());

    for (int i = 0; i < playground.get_size().second; i++)
    {
        for (int j = 0; j < playground.get_size().first; j++)
        {
            if (playground.get_cell_type({j,i}) == empty)
            {
                if ( rand() % 100 + 1 > (100 - obstacle_chance) )
                {
                    playground.set_cell_type({j,i}, obstacle);
                }
            }
        }
    }

    create_path();

    create_objects(trap, (int)sqrt(playground.get_size().first * playground.get_size().second) / 4);
    create_objects(chest, (int)sqrt(playground.get_size().first * playground.get_size().second) / 8);
    create_objects(portal, (int)sqrt(playground.get_size().first * playground.get_size().second) / 6);
}

MapGenerator::MapGenerator(Playground& playground_): playground(playground_) {}

MapGenerator::~MapGenerator() = default;
