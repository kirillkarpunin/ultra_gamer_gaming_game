#ifndef OOP_CONFIG_H
#define OOP_CONFIG_H

#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "../entities/player/PlayerManager.h"

enum keys {non_key, left_key, right_key, up_key, down_key, wait_key, esc_key, invalid_key};

class Config {
private:
    std::map<int, keys> keymap;
    std::vector<std::string> keys_str;

    std::vector<int> ascii_codes_vec;
    std::vector<keys> keys_vec;

public:
    Config(std::string path);
    ~Config();

    keys pressed_key(int n);
    bool is_valid();
};


#endif //OOP_CONFIG_H
