/*
 * graph.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Anisha
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include<vector>
#include "node.h"

using namespace std;

template<typename T>
class graph{
	int num_vertices;
	int num_edges;
	bool directed;
	vector<vector<edge_node> > adjacency_list;
	vector<T>& input;

	public:
		graph(vector<T>& in, bool dir) : num_edges(0), directed(dir), input(in){
			num_vertices = input.size();
			vector<edge_node> s;
			adjacency_list.assign(num_vertices, s);
		};
		int getNumberOfVertices(){ return num_vertices; }
		int getNumberOfEdges() { return num_edges; }
		bool isDirected() { return directed; }
		vector<vector<edge_node> > & getAdjacencyList(){ return adjacency_list; }
		vector<T> & getInput(){ return input; }

		void setNumberOfVertices(int n){ num_vertices = n;}
		void setNumberOfEdges(int n){ num_edges = n;}
		void addEdge(int, int);

};

template<typename T>
void graph<T> :: addEdge(int s, int t){
	if(s >= num_vertices || t >= num_vertices){
		cout<<"Invalid Edge"<<endl;
		return;
	}
	edge_node src(s,0),dest(t, 0);
	adjacency_list[s].push_back(dest);
	adjacency_list[t].push_back(src);
	++num_edges;
}
#endif /* GRAPH_H_ */
