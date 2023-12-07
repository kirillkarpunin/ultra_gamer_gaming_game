#include "InputHandler.h"

InputHandler::InputHandler(const std::string& config_path, const std::string& input_path){
    if (input_path.empty())
        input = new ConsoleInput();
    else
        input = new FileInput(input_path);

    config = new Config(config_path);
}

InputHandler::~InputHandler() {
    delete input;
    delete config;
}

int InputHandler::scan_char() {
    int ch = input->scan();
    if (ch == '$')
        change_input();
    return ch;
}
keys InputHandler::get_key(int ch) {
    return config->pressed_key(ch);
}
keys InputHandler::get_key() {
    int ch = input->scan();
    if (ch == '$')
        change_input();

    return config->pressed_key(ch);
}

void InputHandler::change_input() {
    delete input;
    input = new ConsoleInput();
}

bool InputHandler::is_valid() {
    return config->is_valid();
}



