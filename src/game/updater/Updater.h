#ifndef OOP_UPDATER_H
#define OOP_UPDATER_H

#include "../../world/map/Playground.h"
#include "../../entities/player/PlayerManager.h"
#include "../structure/Level.h"
#include "../../input_output/Renderer.h"
#include "../../input_output/Printer.h"

#include <typeinfo>

class Updater {
private:
    Level* level;

    Renderer* renderer;
    Printer* printer;

    void check_cell_event(IEvent* cell_event);
public:
    Updater(Renderer* renderer_, Printer* printer_, Level* level_);
    ~Updater();

    void check_movement();

    bool defeat();
    bool victory();

    void update_frame();
    void update_menu(Menu* menu);
};


#endif //OOP_UPDATER_H
