#ifndef OOP_PRINTER_H
#define OOP_PRINTER_H

#include <iostream>

class Printer {
public:
    Printer();
    ~Printer();

    void print_logo();
    void print_settings_label();
    void print_pause_label();
    void print_invalid_config();
};


#endif //OOP_PRINTER_H
