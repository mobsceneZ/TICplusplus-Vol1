#include "fibonacci.h"
#include "../require.h"
#include <iostream>
using namespace std;

class IntStack {
    enum { ssize = 100 };
    int stack[ssize];
    int top;
public:
    IntStack() : top(0) {}
    void push(int i) {
        require(top < ssize, "Too many push()es");
        stack[top++] = i;
    }
    int pop() {
        require(top > 0, "Too many pop()s");
        return stack[--top];
    }
    friend class IntStackIter;
};

class IntStackIter {
    IntStack& s;
    int index;
public:
    IntStackIter(IntStack& is) : s(is), index(0) {}
    int operator++() {
        require(index < s.top,
            "iterator moved out of range");
        return s.stack[++index];
    }
    int operator++(int) {
        require(index < s.top,
            "iterator moved out of range");
        return s.stack[index++];
    }
};

int main() {
    IntStack is;
    for (int i = 0; i < 20; i++)
        is.push(fibonacci(i));
    IntStackIter it(is);
    for (int j = 0; j < 20; j++)
        cout << it++ << endl;
}