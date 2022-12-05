#ifndef TWO_HASH_TABLE_H
#define TWO_HASH_TABLE_H

#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include "list.h"
#include <fstream>
#include <iostream>
using namespace std;

class TwoHashTable // This class should have an array of LinkedLists
{
private:
    // Array of LinkedLists
    LinkedList *table = nullptr;
    int _tableSize = -1;

public:
    TwoHashTable(string filename, int tableSize) {
        table = new LinkedList[tableSize];
        _tableSize = tableSize;
        // read the file, ignore the first line
        string line;
        ifstream file(filename);
        if (file.is_open()) {
            while(!file.eof()) {
                getline(file, line);
                // insert new nodes with UPC and description
                insert(UPCEntry(line));
            }
            file.close();
        }
    }

    bool insert(const UPCEntry &item) { // returns true if successful, false otherwise.
        /* 
         * first check which bin contains the shorter
         * linked list, then insert the new object to the front of that shorter linked list. Otherwise, if two linked lists
         * are of the same length, you insert to the bin returned by your first hash function h1.
         */
        LinkedList& list1 = table[item.hash1(_tableSize)];
        LinkedList& list2 = table[item.hash2(_tableSize)];
        if (list1.length() >= list2.length()) {
            list1.add_front(item); // MAKE SURE ADDING UPC ENTRIES IS SUPPORTED
        } else {
            list2.add_front(item);
        }
        return true;

    }
    Position search(const UPCEntry &item) { // if not found, return the default position with both indices set as -1
        /*
         * you use the two hash functions to find out the two bin locations in the table, you will
         * search both two bins in the table since you won’t know which bin contains your search object. 
         */
        // basically loop through table[item.hash1(_tableSize)] to see if you found the item, then repeat for the other list.
        Position p;
        const node *temp = table[item.hash1(_tableSize)].get_head(); // you need to make this a pointer
        while (temp) { // CHANGE THIS LATER
            ++p.indexInBin;
            if (temp->upc.upc == item.upc) { // if the values are the same
                // return position 
                p.indexInTable = item.hash1(_tableSize);
                return p;
            }
            temp = temp->next;
        }
        p.indexInBin = -1;
        temp = table[item.hash2(_tableSize)].get_head(); // you need to make this a pointer
        while (temp) { // CHANGE THIS LATER
            ++p.indexInBin;
            if (temp->upc.upc == item.upc) { // if the values are the same
                // return position 
                p.indexInTable = item.hash2(_tableSize);
                return p;
            }
            temp = temp->next;
        }
        p.indexInBin = -1;
        return p;
    }

    float getStdDev() {
        // binLengths is an int array with the length of all linked lists in the hash table
        int* binLengths = new int[_tableSize];
        for (int i = 0; i < _tableSize; i++)
            binLengths[i] = table[i].length();
        float stdDev = stddev(binLengths, _tableSize);
        delete[] binLengths;
        return stdDev;
    }

private:


    float stddev(int *binLengths, int tableSize)
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};

#endif