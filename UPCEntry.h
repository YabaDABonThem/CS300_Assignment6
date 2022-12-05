#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
using namespace std;

struct UPCEntry
{
    long long upc = -1;
    string desc = "";

    UPCEntry();
    // do we just set the desc to the inputted line?
    UPCEntry(string line) { // line is the unprocessed line from teh csv file
        int i = line.find(",");
        upc = stoll(line.substr(0, i));
        desc = line.substr(i+1, line.length()-1);
    }

    int hash1(int tableSize) const
    {
        return upc % tableSize;
    }

    int hash2(int tableSize) const
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }

};
#endif