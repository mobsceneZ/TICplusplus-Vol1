#include "AutoCounter.h"
#include "OwnerStack.h"
#include "../require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    Stack<AutoCounter> ac;
    Stack<AutoCounter> ac2(false);
    AutoCounter* ap;
    for (int i = 0; i < 10; i++) {
        ap = AutoCounter::create();
        ac.push(ap);
        if (i % 2 == 0)
            ac2.push(ap);
    }
    while (ac2)
        cout << ac2.pop() << endl;
}