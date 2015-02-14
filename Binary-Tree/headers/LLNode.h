#ifndef LLNODE_H
#define LLNODE_H

#include "BTNode.h"

class LLNode{
    BTNode* b_node;
    LLNode* next;

    public:
        // Constructors
        LLNode(BTNode* b) : b_node(b), next(NULL) {}
        LLNode(BTNode* b, LLNode* n) : b_node(b), next(n) {}

        // Setters
        void setData(BTNode* b) { b_node = b; }
        void setNext(LLNode* n) { next = n; }

        // Getters
        BTNode* getData() { return b_node; }
        LLNode* getNext() { return next; }
};

#endif