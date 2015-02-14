#include <iostream>
#include "headers/BTNode.cpp"
#include "headers/LLNode.cpp"
#include "headers/Stack.cpp"
#include "headers/Queue.cpp"
#include "headers/Graph.cpp"

int main(){

	BTNode* b = new BTNode(4);
	LLNode* l = new LLNode(5);
	Stack* s = new Stack;
	Queue* q = new Queue;

	s->push(5);
	s->push(4);
	s->push(3);
	s->push(2);
	s->push(1);

	s->display();

	s->pop();
	s->pop();
	s->pop();

	s->display();

	q->enqueue(5);
	q->enqueue(4);
	q->enqueue(3);
	q->enqueue(2);
	q->enqueue(1);

	q->display();

	q->dequeue();
	q->dequeue();
	q->dequeue();

	q->display();
}