#ifndef OOP_PLAYGROUND_H
#define OOP_PLAYGROUND_H

#include <utility>
#include "Cell.h"
#include "../../sup/observer/IObservable.h"
#include "../../sup/circular_linked_list/CircularLinkedList.h"

constexpr int min_map_width = 10;
constexpr int def_map_width = 28;
constexpr int max_map_width = 32;

constexpr int min_map_height = 10;
constexpr int def_map_height = 14;
constexpr int max_map_height = 32;

class Playground: public IObservable {
private:
    std::pair<int, int> playground_size;
    Cell** map;

    std::pair<int, int> entrance_point;
    std::pair<int, int> exit_point;

    CircularLinkedList portals;

    IObserver* observer;
public:
    Playground(int width = def_map_width, int height = def_map_height);
    ~Playground() override;

    Playground(const Playground& playground);
    Playground& operator = (const Playground& playground);

    Playground(Playground&& playground);
    Playground& operator = (Playground&& playground);

    cell_types get_cell_type(std::pair<int, int> position);
    IEvent* get_cell_event(std::pair<int, int> position);

    void set_cell_type(std::pair<int, int> position, cell_types type);
    std::pair<int, int> get_size();

    std::pair<int, int> get_entrance_point();
    std::pair<int, int> get_exit_point();

    CircularLinkedList& get_portals();

    void add_observer(IObserver* observer_) override;
    void notify() override;
};


#endif //OOP_PLAYGROUND_H
