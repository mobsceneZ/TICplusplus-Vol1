#ifndef DEPENDENCY2_H
#define DEPENDENCY2_H
#include "Dependency1.h"

class Dependency2 {
    Dependency1 d1;
public:
    Dependency2(const Dependency1& dep1) : d1(dep1) {
        std::cout << "Dependency2 construction ";
        print();
    }

    void print() const {
        d1.print();
    }
};

#endif