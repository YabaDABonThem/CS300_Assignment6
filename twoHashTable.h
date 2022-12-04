#include "position.h"
#include "UPCEntry.h"
#include <cmath>
using namespace std;

class TwoHashTable // This class should have an array of LinkedLists
{
public:
    TwoHashTable(string filename, int tableSize);
    bool insert(UPCEntry &item) { // returns true if successful, false otherwise.
        /* 
         * first check which bin contains the shorter
         * linked list, then insert the new object to the front of that shorter linked list. Otherwise, if two linked lists
         * are of the same length, you insert to the bin returned by your first hash function h1.
         */

    }
    Position search(UPCEntry &item) { // if not found, return the default position with both indices set as -1
        /*
         * you use the two hash functions to find out the two bin locations in the table, you will
         * search both two bins in the table since you won’t know which bin contains your search object. 
         */
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