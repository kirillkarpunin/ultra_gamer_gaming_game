#ifndef OOP_IOBSERVABLE_H
#define OOP_IOBSERVABLE_H

#include "IObserver.h"

class IObservable {
public:
    virtual void add_observer(IObserver* observer) = 0;

    virtual void notify() = 0;
    virtual ~IObservable() = default;
};


#endif //OOP_IOBSERVABLE_H
