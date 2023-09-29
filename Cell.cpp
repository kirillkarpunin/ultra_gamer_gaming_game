#include "Cell.h"

cell_types Cell::get_cell_type() const {
    return type;
}

void Cell::set_cell_type(cell_types cell_type) {
    type = cell_type;
}

Cell::Cell(cell_types cell_type) {
    type = cell_type;
}

Cell::~Cell() = default;
