#ifndef GRAPH_H
#define GRAPH_H
#include <list>

class Graph{
	int vertices;
	std::list<int>* adj_list;

public:
	Graph(int v) : vertices(v), adj_list(new std::list<int>[v]) {}

	void addEdge(int source, int dest){
		adj_list[source].push_back(dest);
	}

	
};

#endif