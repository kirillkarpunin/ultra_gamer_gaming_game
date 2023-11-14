#ifndef OOP_CONSOLEINPUT_H
#define OOP_CONSOLEINPUT_H

#include "IInput.h"

class ConsoleInput: public IInput {
public:
    ConsoleInput();
    ~ConsoleInput();

    int scan() final;
};


#endif //OOP_CONSOLEINPUT_H
