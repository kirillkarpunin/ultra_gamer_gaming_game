#ifndef OOP_IOBSERVER_H
#define OOP_IOBSERVER_H

#include <vector>

class IObservable;

class IObserver {
public:
    virtual void update(IObservable* observable_element) = 0;
};


#endif //OOP_IOBSERVER_H
