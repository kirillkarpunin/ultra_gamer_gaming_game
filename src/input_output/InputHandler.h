#ifndef OOP_INPUTHANDLER_H
#define OOP_INPUTHANDLER_H

#include "input_interface/ConsoleInput.h"
#include "input_interface/FileInput.h"
#include "Config.h"

class InputHandler {
private:
    IInput* input;
    Config* config;

    void change_input();
public:
    InputHandler(const std::string& config_path, const std::string& input_path= "");
    ~InputHandler();

    bool is_valid();
    keys get_key();
};


#endif //OOP_INPUTHANDLER_H
