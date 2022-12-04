#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

class LinkedList {
    private:
        node *head = nullptr; // store the head of the LinkedList
        int _length = 0;

    public:
        LinkedList() = default; // default constructor

        // LinkedList(const string& other); // constructor that takes a string
        ~LinkedList(); // destructor
        
        void addFront(int value); // add an item to the front
        int length() const; // get length of this list
        char& operator[](const int n) const; // get string at index n

    private:
        // other helper methods
        void destroy();
};

#endif