#ifndef PSTASH_H
#define PSTASH_H

class PStash {
    int quantity;
    int next;
    void** storage;
    void inflate(int increase);
public:
    PStash() : quantity(0), storage(0), next(0) {}
    ~PStash();
    int add(void* element);
    void* operator[](int index) const; // Fetch
    // Remove the reference from this PStash:
    void* remove(int index);
    int count() const { return next; }
};

#endif