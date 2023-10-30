#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H

#include <iostream>
#include <termcolor.hpp>
#include "../entities/player/PlayerManager.h"

class Renderer {
private:
    PlayerManager& player_manager;
    Playground& playground;
public:
    Renderer(PlayerManager& player_manager_, Playground& playground_);
    ~Renderer();

    void print_player_info();
    void print_map();
    void print_logo();

    void defeat_end();
    void victory_end();
};


#endif //OOP_RENDERER_H
