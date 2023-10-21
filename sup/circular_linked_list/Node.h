#ifndef OOP_NODE_H
#define OOP_NODE_H

#include <utility>

class Node {
public:
    std::pair<int, int> position;
    Node* next;

    Node();
    ~Node();
};


#endif //OOP_NODE_H
