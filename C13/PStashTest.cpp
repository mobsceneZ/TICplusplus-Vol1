#include "PStash.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    PStash intStash;
    for (int i = 0; i < 25; i++)
        intStash.add(new int(i));
    for (int j = 0; j < intStash.count(); j++)
        cout << "intStash[" << j << "] = "
             << *(int*)intStash[j] << endl;
    for (int k = 0; k < intStash.count(); k++)
        delete intStash.remove(k);
    ifstream in("PStashTest.cpp");
    assure(in, "PStashTest.cpp");
    PStash stringStash;
    string line;
    while (getline(in, line))
        stringStash.add(new string(line));
    for (int u = 0; stringStash[u]; u++)
        cout << "stringStash[" << u << "] = "
             << *(string*)stringStash[u] << endl;
    for (int v = 0; v < stringStash.count(); v++)
        delete (string*)stringStash.remove(v);
}