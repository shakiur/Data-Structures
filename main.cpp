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
	Graph* g = new Graph(4);

	s->push(5);
	s->push(4);
	s->push(3);
	s->push(2);
	s->push(1);

	std::cout << "Stack: ";
	s->display();

	s->pop();
	s->pop();
	s->pop();

	std::cout << "Stack: ";
	s->display();

	q->enqueue(5);
	q->enqueue(4);
	q->enqueue(3);
	q->enqueue(2);
	q->enqueue(1);

	std::cout << "Queue: ";
	q->display();

	q->dequeue();
	q->dequeue();
	q->dequeue();

	std::cout << "Queue: ";
	q->display();

	g->addEdge(0, 1);
	g->addEdge(0, 2);
	g->addEdge(3, 3);

	g->DFS();

	


}