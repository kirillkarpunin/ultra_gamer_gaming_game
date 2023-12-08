#include "LoggerMenu.h"

void LoggerMenu::init() {
    options = {
            {"console", console},
            {"console and file", console_file},
            {"file", file}
    };

    label = "\n\t| WHERE TO LOG ??? |\n\n";
}
