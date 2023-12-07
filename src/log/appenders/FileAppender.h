#ifndef OOP_FILEAPPENDER_H
#define OOP_FILEAPPENDER_H

#include <fstream>
#include "Appender.h"

class FileAppender : public Appender{
private:
    std::fstream file;
public:
    FileAppender(std::string path);
    void append(Message &message) override;
};


#endif //OOP_FILEAPPENDER_H
