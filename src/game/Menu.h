#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <utility>
#include <string>
#include <vector>

enum menu_options{play_game, settings, exit_game, return_main_menu, resume, next_level, new_game};
using option = std::pair<std::string, menu_options>;


class Menu {
private:
    std::vector<option> options;
    int curr_option;
    bool active;
public:
    Menu(std::vector<option> options_);
    ~Menu();

    void option_up();
    void option_down();

    int get_curr_option() const;
    std::vector<option>& get_options();

    menu_options choose_option() const;

    bool is_active() const;
    void close();

};


#endif //OOP_MENU_H
