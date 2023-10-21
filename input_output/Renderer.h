#ifndef OOP_RENDERER_H
#define OOP_RENDERER_H

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define YEL "\e[0;33m"
#define COLOR_RESET "\e[0m"

#include <iostream>
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
    void escape_end();
};


#endif //OOP_RENDERER_H
