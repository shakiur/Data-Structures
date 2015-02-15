#ifndef HASHENTRY_H
#define HASHENTRY_H

class HashEntry{
	int key;
	int value;

	HashEntry* next;

public:
	HashEntry(int k, int v) : key(k), value(v), next(NULL) {}

	int getKey(){ return key; }
	int getValue() { return value; }
	HashEntry* getNext() { return next; }

	void setValue(int v) { value = v; }
	void setNext(HashEntry* n) { next = n; }
};

#endif