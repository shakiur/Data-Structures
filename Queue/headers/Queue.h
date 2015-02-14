#ifndef QUEUE_H
#define QUEUE_H

#include "LLNode.h"

class Queue{
    LLNode* front;
    LLNode* back;

    public:
        Queue() : front(NULL), back(NULL){}

        bool isEmpty() { return front == NULL; }

        void enqueue(int d){
            LLNode* n = new LLNode(d);

            if(front == NULL){
                front = n;
                back = n;
            }
            else{
                back->setNext(n);
                back = n;
            }
        }

        LLNode* dequeue(){
            if(front){

                LLNode* temp = front;
                front = front->getNext();
                return temp;
                
            }
            else{
                return NULL;
            }
        }
};

#endif