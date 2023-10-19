#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H

#include <iostream>
#include "../entities/player/Player-Manager.h"

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
};


#endif //OOP_RENDERER_H
