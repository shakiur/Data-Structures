#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <queue>

class Graph{
	int vertices;
	std::list<int>* adj_list;
    void DFSPrintAdj(bool* visited, std::list<int>* adj_list, int pos){
        if(!visited[pos]){

            visited[pos] = true;
            std::cout << pos << " ";
            
            for(std::list<int>::iterator it = adj_list[pos].begin(); it != adj_list[pos].end(); it++){
                if(!visited[*it]){
                    visited[*it] = true;
                    std::cout << *it << " ";
                }
            }

            std::cout << std::endl;
        }
    }

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
            DFSPrintAdj(visited, adj_list, i);
        }
    }

    void DFS(int cur_v){
        bool visited[vertices];

        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }

        DFSPrintAdj(visited, adj_list, cur_v);
    }

    void BFS(int start_v){
        bool visited[vertices];

        for(int i = 0; i < vertices; i++){
            visited[i] = false;
        }

        // queue to hold all visited vertices
        std::queue<int> q;

        q.push(start_v);

        int cur_v;

        while(!q.empty()){
            cur_v = q.front();
            q.pop();

            std::cout << cur_v << " ";
            visited[cur_v] = true;

            for(std::list<int>::iterator it = adj_list[cur_v].begin(); it != adj_list[cur_v].end(); it++){
                if(!visited[*it]){
                    q.push(*it);
                }
            }

        }
    }


	
};

#endif