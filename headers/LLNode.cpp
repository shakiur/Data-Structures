#ifndef LLNODE_H
#define LLNODE_H

class LLNode {
	int data;
	LLNode* next;

public:
	LLNode(int d) : data(d), next(NULL) {}
	LLNode(int d, LLNode* n) : data(d), next(n) {}

	// Getters
	int getData() { return data; }
	LLNode* getNext() { return next; }

	// Setters
	void setData(int d) { data = d; }
	void setNext(LLNode* n) { next = n; }

};

#endif