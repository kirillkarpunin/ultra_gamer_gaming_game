#include "FileInput.h"

int FileInput::scan() {
    return file.get();
}

FileInput::FileInput(std::string path){
    file.open(path);
}
FileInput::~FileInput() = default;
