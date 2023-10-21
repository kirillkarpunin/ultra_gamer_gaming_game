#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
    len = 0;

    head = new Node();
    head->next = head;
}

void CircularLinkedList::add(std::pair<int, int> position_) {
    if (len == 0){
        head->position = position_;
        len++;
        return;
    }

    Node* tmp = head;
    while (tmp->next != head){
        tmp = tmp->next;
    }

    tmp->next = new Node();
    tmp->next->position = position_;
    tmp->next->next = head;
    len++;
}

void CircularLinkedList::move_head() {
    head = head->next;
}

std::pair<int, int> CircularLinkedList::get_position() {
    return head->position;
}

CircularLinkedList::~CircularLinkedList() {
    for (int i = 0; i < len; i++){
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
}
