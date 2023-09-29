#ifndef OOP_PLAYGROUND_H
#define OOP_PLAYGROUND_H

#include <utility>
#include "Cell.h"

class Playground {
private:
    std::pair<int, int> playground_size;
    Cell** map;

    std::pair<int, int> entrance_point;
    std::pair<int, int> exit_point;

    void create_map();
public:
    Playground(int width = 4, int height = 4);
    ~Playground();

    void print_map();
    cell_types get_cell_type_by_coords(int x, int y);
    std::pair<int, int>& get_size();
};


#endif //OOP_PLAYGROUND_H
