#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell;
enum cell_types{empty, obstacle, trap, chest, portal, entrance, exit_};

#include "../events/Trap.h"
#include "../events/Chest.h"

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
