#include <iostream>
#include <vector>
#include "../require.h"
using namespace std;

class Obj {
    static int i, j;
public:
    void f() { cout << i++ << endl; }
    void g() { cout << j++ << endl; }
};

int Obj::i = 47;
int Obj::j = 11;

class ObjContainer {
    vector<Obj*> a;
public:
    void add(Obj* obj) { a.push_back(obj); }
    class SmartPointer;
    friend SmartPointer;
    class SmartPointer {
        ObjContainer& oc;
        unsigned int index;
    public:
        SmartPointer(ObjContainer& objc) : oc(objc) {
            index = 0;
        }
        bool operator++() {
            if (index >= oc.a.size()) return false;
            if (oc.a[++index] == 0) return false;
            return true;
        }
        bool operator++(int) {
            return operator++();
        }
        Obj* operator->() const {
            require(oc.a[index] != 0, "Zero value "
                "returned by SmartPointer::operator->()");
            return oc.a[index];
        }
    };

    SmartPointer begin() {
        return SmartPointer(*this);
    }
};

int main() {
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;
    for (int i = 0; i < sz; i++)
        oc.add(&o[i]);
    ObjContainer::SmartPointer sp = oc.begin();
    do {
        sp->f();
        sp->g();
    } while (++sp);
}