#include "Useful.h"

class Y {
    int i;
public:
    X x;
    Y() { i = 0; }
    void f(int ii) { i = ii; }
    int g() const { return i; }
};

int main() {
    Y y;
    y.f(47);
    y.x.set(37);
}