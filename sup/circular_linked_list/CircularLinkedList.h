#ifndef OOP_CIRCULARLINKEDLIST_H
#define OOP_CIRCULARLINKEDLIST_H

#include "Node.h"

class CircularLinkedList {
    Node* head;
    int len;
public:
    CircularLinkedList();
    ~CircularLinkedList();

    void add(std::pair<int, int> position_);
    void move_head();
    std::pair<int, int> get_position();
};


#endif //OOP_CIRCULARLINKEDLIST_H
