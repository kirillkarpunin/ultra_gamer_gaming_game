#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <utility>
#include <string>
#include <vector>

#include "../input_output/Config.h"

enum menu_options{nothing, play_game, settings, exit_game, return_main_menu, resume, next_level, new_game, change_size};
using option = std::pair<std::string, menu_options>;


class Menu {
private:
    std::vector<option> options;
    int curr_option;
    bool active;

    void option_up();
    void option_down();
    menu_options choose_option() const;

public:
    Menu(std::vector<option> options_);
    ~Menu();

    int get_curr_pos() const;
    std::vector<option>& get_options();

    menu_options update(keys key);

    bool is_active() const;
    void close();

};


#endif //OOP_MENU_H
