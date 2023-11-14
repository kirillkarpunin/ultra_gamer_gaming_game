#include "ConsoleInput.h"
#include "../../../include/getch/getch.h"


int ConsoleInput::scan() {
    return getch();
}

ConsoleInput::ConsoleInput() = default;
ConsoleInput::~ConsoleInput() = default;
