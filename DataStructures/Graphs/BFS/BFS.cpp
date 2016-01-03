/*
 * BFS.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "graph.h"
#include<queue>

using namespace std;

template<typename T>
class BFS{
	bool* processed;
	bool* discovered;
	int* parent;
	graph<T>* g;

	public:
		BFS(graph<T>* gh) : g(gh){
			processed = new bool[g->getNumberOfVertices()];
			discovered = new bool[g->getNumberOfVertices()];
			parent = new int[g->getNumberOfVertices()];
		};

		void initialize_traverse();
		void traverse(int);
		void process_vertex_early(int v);
		void process_edge(int, int);
		void process_vertex_late(int v);
};

template<typename T>
void BFS<T> :: initialize_traverse(){
	for(int i = 0 ; i < g->getNumberOfVertices(); ++i){
		discovered[i] = false;
		processed[i] = false;
		parent[i] = -1;
	}
}

template<typename T>
void BFS<T> :: traverse(int s){
	queue<int> q;

	initialize_traverse();

	discovered[s] = true;
	q.push(s);

	while(!q.empty()){
		int v = q.front();
		q.pop();
		process_vertex_early(v);
		vector<vector<edge_node> > & list = g->getAdjacencyList();
		vector<edge_node>& y = list[v];

		for(unsigned i = 0; i < y.size(); ++i){
			if(!processed[y[i].getValue()] || g->isDirected()){
				process_edge(v, y[i].getValue());
			}

			if(!discovered[y[i].getValue()]){
				q.push(y[i].getValue());
				discovered[y[i].getValue()] = true;
				parent[y[i].getValue()] = v;
			}
		}

		processed[v] = true;
	}
}

template<typename T>
void BFS<T> :: process_vertex_early(int v){
	cout<<"Process vertex: "<<g->getInput()[v];
	cout<<endl;
}

template<typename T>
void BFS<T> :: process_edge(int s, int t){
	cout<<"Process edge: "<<g->getInput()[s]<<" - "<<g->getInput()[t];
	cout<<endl;
}

template<typename T>
void BFS<T> :: process_vertex_late(int v){
	//cout<<"Process vertex: "<<g->getInput()[v];
}

