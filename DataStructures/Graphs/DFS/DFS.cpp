/*
 * DFS.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "graph.h"
#include "node.h"

using namespace std;

template<typename T>
class DFS{
	bool* processed;
	bool* discovered;
	int* parent;
	int* start_time;
	int* end_time;
	graph<T>* g;
	int time;

	public:
		DFS(graph<T>* gh) : g(gh), time(0){
			processed = new bool[g->getNumberOfVertices()];
			discovered = new bool[g->getNumberOfVertices()];
			parent = new int[g->getNumberOfVertices()];
			start_time = new int[g->getNumberOfVertices()];
			end_time = new int[g->getNumberOfVertices()];
			initialize_traverse();
		};

		void initialize_traverse();
		void traverse(int);
		void process_vertex_early(int v);
		void process_edge(int, int);
		void process_vertex_late(int v);
};

template<typename T>
void DFS<T> :: initialize_traverse(){
	for(int i = 0 ; i < g->getNumberOfVertices(); ++i){
		discovered[i] = false;
		processed[i] = false;
		parent[i] = -1;
	}
}

template<typename T>
void DFS<T> :: traverse(int s){


	discovered[s] = true;
	++time;
	start_time[s] = time;
	process_vertex_early(s);
	vector<vector<edge_node> > & list = g->getAdjacencyList();
	vector<edge_node>& y = list[s];

	for(unsigned i = 0; i < y.size(); ++i){
		if(!discovered[y[i].getValue()]){
						process_edge(s, y[i].getValue());
						parent[y[i].getValue()] = s;
						traverse(y[i].getValue());

		} else if(!processed[y[i].getValue()] || g->isDirected()){
				process_edge(s, y[i].getValue());
		}
	}

	process_vertex_late(s);
	++time;
	end_time[s]= time;

	processed[s] = true;

}

template<typename T>
void DFS<T> :: process_vertex_early(int v){
	cout<<"Process vertex: "<<g->getInput()[v];
	cout<<endl;
}

template<typename T>
void DFS<T> :: process_edge(int s, int t){
	cout<<"Process edge: "<<g->getInput()[s]<<" - "<<g->getInput()[t];
	cout<<endl;
}

template<typename T>
void DFS<T> :: process_vertex_late(int v){
	//cout<<"Process vertex: "<<g->getInput()[v];
}


