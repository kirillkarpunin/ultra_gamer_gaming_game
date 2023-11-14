#ifndef OOP_FILEINPUT_H
#define OOP_FILEINPUT_H

#include <fstream>
#include <string>
#include "IInput.h"

class FileInput: public IInput{
private:
    std::fstream file;
public:
    FileInput(std::string path);
    ~FileInput();

    int scan() final;
};


#endif //OOP_FILEINPUT_H
