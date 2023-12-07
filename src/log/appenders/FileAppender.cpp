#include "FileAppender.h"

FileAppender::FileAppender(std::string path) {
    file.open(path, std::ofstream::out | std::ofstream::trunc);
}

void FileAppender::append(Message &message) {
    file << time() << message << "\n";
}
