#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H

#include <iostream>
#include <cstdlib>

#include "../../include/termcolor/termcolor.hpp"
#include "../entities/player/PlayerManager.h"
#include "../game/menu/MenuHandler.h"

constexpr bool fog = true;
constexpr int fog_rad = 2;

class Renderer {
public:
    Renderer();
    ~Renderer();

    void terminal_clear();
    void print_player_info(PlayerManager& player_manager);
    void render_map(Playground& playground, PlayerManager& player_manager);
    void print_menu(Menu& menu);
};


#endif //OOP_RENDERER_H
