#ifndef STACK_H
#define STACK_H
#include "LLNode.cpp"

class Stack{
	LLNode* top;

public:
	Stack() : top(NULL){}

	LLNode* pop(){

		LLNode* temp = top;

		if(top)
			top = top->getNext();

		return temp;
	}

	void push(int d){
		LLNode* new_top = new LLNode(d, top);
		top = new_top;
	}

	void display(){
		LLNode* temp = top;

		while(temp){
			std::cout << temp->getData() << " ";
			temp = temp->getNext();
		}
		std::cout << std::endl;

	}
};

#endif