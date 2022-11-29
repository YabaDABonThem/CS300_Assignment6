#include "position.h"
#include "UPCEntry.h"
#include <cmath>
using namespace std;

class TwoHashTable
{
public:
    TwoHashTable(string filename, int tableSize);
    bool insert(UPCEntry &item); // returns true if successful, false otherwise.
    Position search(UPCEntry &item); // if not found, return the default position with both indices set as -1
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