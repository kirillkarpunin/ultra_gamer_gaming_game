#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <utility>
#include <string>
#include <vector>
#include <iostream>

#include "../../sup/observer/IObservable.h"
#include "../../input_output/Config.h"

class Renderer;
enum menu_options{play_game, settings, exit_game, return_main_menu, resume, new_game, change_size, console, console_file, file};
using option = std::pair<std::string, menu_options>;

class Menu: public IObservable{
protected:
    std::vector<option> options;
    std::string label;
    int curr_option;
    bool active;

    IObserver* observer;

    void print();

public:
    Menu();
    ~Menu();

    virtual void init() = 0;

    void option_up();
    void option_down();
    menu_options choose_option() const;

    bool is_active() const;
    void close();

    void add_observer(IObserver* observer_) override;
    void notify() override;

    friend std::ostream& operator<< (std::ostream& stream, Menu& menu);
};


#endif //OOP_MENU_H
