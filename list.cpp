#include "list.h"
#include <iostream>

void LinkedList::addFront(int value) {
    ++_length;
    node *temp = new node(value);
    temp->next = head;
    head = temp;

}

int LinkedList::length() const {
    return _length;
}

void LinkedList::destroy(){
    while(head) {
        node *prev = head;
        head = head->next;
        delete prev;
    }
}

LinkedList::~LinkedList() {
    destroy();
}