#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
using namespace std;

struct UPCEntry
{
    long long upc = -1;
    string desc = "";
    UPCEntry();
    UPCEntry(string line);

    int hash1(int tableSize)
    {
        return upc % tableSize;
    }

    int hash2(int tableSize)
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }
};
#endif