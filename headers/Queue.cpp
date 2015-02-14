#ifndef QUEUE_H
#define QUEUE_H
#include "LLNode.cpp"

class Queue{
	LLNode* front;
	LLNode* back;

public:
	Queue() : front(NULL), back(NULL) {}

	void enqueue(int d){
		LLNode* entry = new LLNode(d);

		if(front == NULL)
			front = entry;
		else
			back->setNext(entry);

		back = entry;
	}

	LLNode* dequeue(){
		LLNode* temp_front = front;

		front = front->getNext();

		if(front == back)
			back = back->getNext();

		return temp_front;
	}

	void display(){
		LLNode* temp = front;

		while(temp){
			std::cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		
		std::cout << std::endl;
	}
};

#endif