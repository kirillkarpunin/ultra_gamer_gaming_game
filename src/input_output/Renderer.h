#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H

#include <iostream>
#include <cstdlib>

#include "../../include/termcolor/termcolor.hpp"
#include "../entities/player/PlayerManager.h"
#include "../game/structure/Menu.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void terminal_clear();
    void print_player_info(PlayerManager& player_manager);
    void render_map(Playground& playground, PlayerManager& player_manager);
    void print_menu(Menu& menu);

    void print_level(int level);

    void defeat_end(int level);
    void victory_end(int level);
};


#endif //OOP_RENDERER_H
