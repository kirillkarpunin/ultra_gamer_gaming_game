#include "Config.h"

Config::Config(std::string path){
    keys_str = {"left_key", "right_key", "up_key", "down_key", "wait_key", "esc_key"};

    std::fstream config_file(path);

    if (config_file.is_open()) {
        keymap.clear();

        std::string line;
        int ascii_code, key_i;

        while (config_file)
        {
            std::getline(config_file, line, ':');
            try {
                ascii_code = std::stoi(line, nullptr, 10);
            }
            catch (std::exception &err){
                std::getline(config_file, line, '\n');
                break;
            }
            if (keymap[ascii_code] != non_key)
                break;

            std::getline(config_file, line, '\n');

            key_i = (int)(std::find(keys_str.begin(), keys_str.end(), line) - keys_str.begin());

            keys key = invalid_key;
            if (key_i < (int)keys_str.size()){
                key = (keys)(key_i+1);
                keys_str[key_i] = "invalid_key";
            }
            if (key == invalid_key)
                break;

            keymap[ascii_code] = key;
            ascii_codes_vec.push_back(ascii_code);
            keys_vec.push_back(key);

            if (config_file.eof()) break;
        }
    }

}

bool Config::is_valid() {
    return keys_vec.size() == keys_str.size();
}

keys Config::pressed_key(int n) {
    if (std::find(ascii_codes_vec.begin(), ascii_codes_vec.end(), n) != ascii_codes_vec.end())
        return keymap[n];
    else
        return invalid_key;
}

Config::~Config() = default;
