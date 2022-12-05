#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"
#include "UPCEntry.h"

using namespace std;

class LinkedList {
    private:
        node *head = nullptr; // store the head of the LinkedList
        int _length = 0;

    public:
        LinkedList() = default; // default constructor

        // LinkedList(const string& other); // constructor that takes a string
        ~LinkedList() {
            while(head) {
                node *prev = head;
                head = head->next;
                delete prev;
            }
        } // destructor
        
        void add_front(const UPCEntry& value) {
            ++_length;
            node *temp = new node(value);
            temp->next = head;
            head = temp;
        } // add an item to the front
        int length() const {
            return _length;
        } // get length of this list
        node* get_head() {
            return head;
        } // get the pointer to the head

};

#endif