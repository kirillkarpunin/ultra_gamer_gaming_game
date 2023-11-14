#ifndef OOP_IINPUT_H
#define OOP_IINPUT_H

class IInput{
public:
    virtual int scan() = 0;
    virtual ~IInput() = default;
};

#endif //OOP_IINPUT_H
