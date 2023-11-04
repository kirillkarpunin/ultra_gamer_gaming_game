#ifndef OOP_GETCH_H
#define OOP_GETCH_H

#include <termios.h>
#include <iostream>
#include <unistd.h>

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

#endif //OOP_GETCH_H