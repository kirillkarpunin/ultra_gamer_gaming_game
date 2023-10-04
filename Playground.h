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
    void create_objects_on_map(cell_types type, int n);

public:
    Playground(int width = 4, int height = 4);
    ~Playground();

    Playground(const Playground& playground);
    Playground& operator = (const Playground& playground);

    Playground(Playground&& playground);
    Playground& operator = (Playground&& playground);

    void print_map() const;
    cell_types get_cell_type_by_coords(std::pair<int, int> coords);
    void change_cell_type_by_coords(std::pair<int, int> coords, cell_types type);
    std::pair<int, int>& get_size();
};


#endif //OOP_PLAYGROUND_H
