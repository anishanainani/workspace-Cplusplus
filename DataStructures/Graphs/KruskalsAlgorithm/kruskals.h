/*
 * kruskals.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Anisha
 */

#ifndef KRUSKALS_H_
#define KRUSKALS_H_

#include<iostream>
#include "disjointSets.h"
#include "graph.h"
#include "node.h"
#include<map>
#include<vector>

using namespace std;

class edge{
	char node1;
	char node2;
	public:
		edge(){};
		edge(char c, char d) : node1(c), node2(d){};
		char getNode1(){ return node1; }
		char getNode2(){ return node2; }
};

class kruskals{
	graph<char> *g;

	public:
		kruskals(graph<char>* gh) : g(gh){};
		void findMST();
};



void kruskals :: findMST(){


	map<int, vector<edge> > edge_table;

	vector<vector<edge_node> > adj_list =  g->getAdjacencyList();
	for(int i = 0; i < g->getNumberOfVertices(); ++i){
		for(unsigned j = 0; j < adj_list[i].size(); ++j){
			edge e(g->getInput()[i],g->getInput()[adj_list[i][j].getValue()]);
			int w = adj_list[i][j].getWeight() ;
			edge_table[w].push_back(e);
		}
	}

	disjointSets d;
	for(int i = 0; i < g->getNumberOfVertices(); ++i){
		d.makeSet(g->getInput()[i]);
	}

	cout<<"Minimum Spanning tree : "<<endl;
	for(typename map<int, vector<edge> > :: iterator it =edge_table.begin(); it!=edge_table.end(); ++it){
			int nextMinWeight = (*it).first;
			for(unsigned i = 0; i < (*it).second.size(); ++i){
				edge & e = (*it).second[i];
				if(d.find(e.getNode1()) != d.find(e.getNode2())){
					cout<<e.getNode1()<<e.getNode2()<<" "<<nextMinWeight<<endl;
					d.unionSets(e.getNode1(),e.getNode2());
				}
			}
		}

}

#endif /* KRUSKALS_H_ */
