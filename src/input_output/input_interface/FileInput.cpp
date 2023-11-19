#include "FileInput.h"

int FileInput::scan() {
    if (file.eof())
        return '$';
    return file.get();
}

FileInput::FileInput(std::string path){
    file.open(path);
}
FileInput::~FileInput() = default;
