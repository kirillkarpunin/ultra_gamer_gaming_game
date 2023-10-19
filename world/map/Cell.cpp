#include "Cell.h"

cell_types Cell::get_type() const {
    return type;
}

void Cell::set_type(cell_types cell_type) {
    type = cell_type;
    switch (cell_type) {
        case trap:
//            event_ptr = new Trap();
//            break;
        case chest:
            event_ptr = new Chest();
            break;
        default:
            event_ptr = nullptr;
            break;
    }
}

IEvent* Cell::get_event() const {
    return event_ptr;
}

Cell::Cell(cell_types cell_type) {
    type = cell_type;
    switch (cell_type) {
//        case trap:
//            event_ptr = new Trap();
//            break;
        case chest:
            event_ptr = new Chest();
            break;
        default:
            event_ptr = nullptr;
            break;
    }
}

Cell::~Cell() {
    delete event_ptr;
}
