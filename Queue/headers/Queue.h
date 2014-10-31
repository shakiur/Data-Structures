#ifndef QUEUE_H
#define QUEUE_H

#include "LLNode.h"

class Queue{
    LLNode* front;
    LLNode* tail;

    public:
        Queue() : front(NULL), tail(NULL){}

        void enqueue(int d){
            LLNode* n = new LLNode(d);

            if(front == NULL){
                front = n;
                tail = n;
            }
            else{
                tail->setNext(n);
                tail = n;
            }
        }

        LLNode* dequeue(){
            if(front){

                // If only 1 element in queue
                if(front == tail)
                    tail = tail->getNext();

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