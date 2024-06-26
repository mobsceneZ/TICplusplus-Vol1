#include <iostream>
#include <string>
using namespace std;

class WithCC {
public:
    WithCC() {}
    WithCC(const WithCC&) {
        cout << "WithCC(WithCC&)" << endl;
    }
};

class WoCC {
    string id;
public:
    WoCC(const string& ident = "") : id(ident) {}
    void print(const string& msg = "") const {
        if (msg.size() != 0) cout << msg << ": ";
        cout << id << endl;
    }
};

class Composite {
    WithCC withcc;
    WoCC wocc;
public:
    Composite() : wocc("Composite()") {}
    void print(const string& msg = "") const {
        wocc.print(msg);
    }
};

int main() {
    Composite c;
    c.print("Contents of c");
    cout << "Calling Composite copy-constructor"
         << endl;
    Composite c2 = c;
    c2.print("Contents of c2");
}