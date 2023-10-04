#ifndef OOP_CELL_H
#define OOP_CELL_H

enum cell_types{empty, obstacle, trap, chest, entrance, exit_, portal};

class Cell {
private:
    cell_types type;
    // event pointer
public:
    Cell(cell_types cell_type = empty);
    ~Cell();

    void set_cell_type(cell_types cell_type);
    cell_types get_cell_type() const;
};


#endif //OOP_CELL_H
