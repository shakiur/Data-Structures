#ifndef HASHENTRY_H
#define HASHENTRY_H

class HashEntry{
    
    int key;
    int value;
    HashEntry* next;

    public:
    // Constructor
    HashEntry(int k, int v) : key(k), value(v), next(NULL) {};

    // Getters
    int getValue() { return value; }
    int getKey() { return key; }
    HashEntry* getNext() { return next; }

    // Setters
    void setValue(int newVal) { value = newVal; }
    void setKey(int newKey) { key = newKey; }
    void setNext(HashEntry* newNext) { next = newNext; }
};

#endif



