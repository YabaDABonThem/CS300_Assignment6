#include "list.h"
#include <iostream>

// LinkedList::LinkedList(const string& other) {
//     // fenceposting is dum asf
//     Node * *ptr = &head;

//     for(int i = 0; i < other.size(); ++i) {
//         *ptr = new Node();
//         (*ptr)->data = other[i];
//         // (*ptr)->up = ; // what should we set the long to equal to?
//         ptr = &(*ptr)->next;
//     }
// }

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