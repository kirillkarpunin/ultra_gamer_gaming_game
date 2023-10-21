#ifndef OOP_CELL_H
#define OOP_CELL_H


#include "../events/Trap.h"
#include "../events/Chest.h"
#include "../events/ExplodeWall.h"
#include "../events/Teleport.h"

enum cell_types{empty, obstacle, trap, chest, portal, entrance, exit_};

class Cell {
private:
    cell_types type;
    IEvent* event_ptr;
public:
    Cell(cell_types cell_type = empty);
    ~Cell();

    void set_type(cell_types cell_type);
    cell_types get_type() const;
    IEvent* get_event() const;
};


#endif //OOP_CELL_H
