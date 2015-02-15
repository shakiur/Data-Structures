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

    void DFS(){
        bool visited[vertices];

        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }

        for(int i = 0; i < vertices; i++){
            if(!visited[i]){
                visited[i] = true;
                std::cout << i << " ";
                DFSPrintAdj(visited, adj_list, i);
                std::cout << std::endl;
            }
        }
    }

    void DFSPrintAdj(bool* visited, std::list<int>* adj_list, int pos){
        for(std::list<int>::iterator it = adj_list[pos].begin(); it != adj_list[pos].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                std::cout << *it << " ";
            }
        }
    }

	
};

#endif