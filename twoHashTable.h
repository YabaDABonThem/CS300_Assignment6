#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include "list.cpp"
using namespace std;

class TwoHashTable // This class should have an array of LinkedLists
{
private:
    // Array of LinkedLists
    LinkedList **table = nullptr;
    int _tableSize = -1;

public:
    TwoHashTable(string filename, int tableSize) {
        *table = new LinkedList[tableSize];
        _tableSize = tableSize;
    }

    bool insert(UPCEntry &item) { // returns true if successful, false otherwise.
        /* 
         * first check which bin contains the shorter
         * linked list, then insert the new object to the front of that shorter linked list. Otherwise, if two linked lists
         * are of the same length, you insert to the bin returned by your first hash function h1.
         */
        LinkedList list1 = *table[item.hash1(_tableSize)];
        LinkedList list2 = *table[item.hash2(_tableSize)];
        if (list1.length() >= list2.length()) {
            list1.add_front(item); // MAKE SURE ADDING UPC ENTRIES IS SUPPORTED
        } else {
            list2.add_front(item);
        }
        return true;

    }
    Position search(UPCEntry &item) { // if not found, return the default position with both indices set as -1
        /*
         * you use the two hash functions to find out the two bin locations in the table, you will
         * search both two bins in the table since you won’t know which bin contains your search object. 
         */
        // basically loop through table[item.hash1(_tableSize)] to see if you found the item, then repeat for the other list.
        node temp = table[item.hash1(_tableSize)]->get_head(); // you need to make this a pointer
        while (false) { // CHANGE THIS LATER
            if (temp.data == item) {
                // return position 
            }
            // temp = temp.next;
        }
    }
    float getStdDev();

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