#include "list.h"
#include <iostream>

void LinkedList::add_front(UPCEntry value) {
    ++_length;
    node *temp = new node(value);
    temp->next = head;
    head = temp;

}

int LinkedList::length() const {
    return _length;
}

LinkedList::~LinkedList() {
    while(head) {
        node *prev = head;
        head = head->next;
        delete prev;
    }
}

node LinkedList::get_head() {
    return *head;
}