#include <iostream>

#include "twoHashTable.h"
#include "UPCEntry.h"
#include "list.cpp"
#include <assert.h>
using namespace std;

float grade = 0;

void autograde(string name, bool result, float points)
{
    if (result)
        grade += points;
    else
    {
        cout << "error: " << name << endl;
    }
}

int main()
{
    int testSize = 6;
    UPCEntry *items[testSize];
    items[0] = new UPCEntry("753950001954,Doctor's Best Best Curcumin C3 Complex 1000mg Tablets - 120 Ct");
    items[1] = new UPCEntry("025800024117,Weight Watchers Smart Ones Smart Creations");
    items[2] = new UPCEntry("079927020217,\"Unique \"\"splits\"\" Split-open Pretzel Extra Dark\"");
    items[3] = new UPCEntry("1638098830,Weleda Bar Soap Rose - 3.5 Oz");
    items[4] = new UPCEntry("895172001432,Pure Life Body Lotion Coconut And Mango - 15.0 Fl Oz");
    items[5] = new UPCEntry("995172001432,Pure Life Body Lotion Coconut And Mango - 14.9 Fl Oz");

    TwoHashTable *table = new TwoHashTable("test_data.csv", 3);
    cout << "-- sample run start --" << endl;
    assert(abs(table->getStdDev() - 0.471404f) < 1e-6);
    Position pos = table->search(*items[0]);
    assert(pos.indexInTable == 0 && pos.indexInBin == 3);
    pos = table->search(*items[1]);
    assert(pos.indexInTable == -1 && pos.indexInBin == -1);
    pos = table->search(*items[2]);
    assert(pos.indexInTable == 1 && pos.indexInBin == 0);
    cout << "-- sample run pass --" << endl;

    grade += 1;

    int tableSize[3] = {100000, 1000, 100};
    float correct_std[3] = {1.78235, 21.457, 15.4253};
    int correct_pos[3][6][2] = {{{1954, 5}, {24117, 3}, {20217, 3}, {98830, 0}, {-1, -1}, {-1, -1}},
                                {{954, 49}, {117, 109}, {217, 128}, {830, 0}, {-1, -1}, {-1, -1}},
                                {{54, 1105}, {17, 916}, {17, 1108}, {30, 0}, {-1, -1}, {-1, -1}}};
    for (int n = 0; n < 3; n++)
    {
        TwoHashTable *table = new TwoHashTable("grocery_upc_database.csv", tableSize[n]);
        float std = table->getStdDev();
        cout << "Table size = " << tableSize[n] << ", stddev = " << std << endl;
        autograde("std", abs(std - correct_std[n]) < 1e-3, 4);

        for (int i = 0; i < testSize; i++)
        {
            Position pos = table->search(*items[i]);
            cout << "      [" << pos.indexInTable << "," << pos.indexInBin << "]" << endl;
            autograde("index in table", pos.indexInTable == correct_pos[n][i][0], 1);
            autograde("index in bin", pos.indexInBin == correct_pos[n][i][1], 0.5);
        }
    }
    cout << "Your total grade is: " << grade << endl;
    return 0;
}