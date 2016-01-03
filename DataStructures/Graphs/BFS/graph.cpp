/*
 * graph.cpp
 *
 *  Created on: Jan 9, 2015
 *      Author: Komani
 */

/*
 * graph.h
 *
 *  Created on: Jan 8, 2015
 *      Author: Komani
 */


#include<iostream>
#include "graph.h"

using namespace std;

graph :: graph(){
			nvertices = 0;
			nedges = 0;
			directed = true;
};

graph :: graph(int nv,bool dir){
			nvertices = nv;
			nedges = 0;

			degree = new int[nvertices+1];
			for(int i = 1; i <= nvertices; i++){
				degree[i] = 0;
			}

			edges = new vertex*[nvertices+1];
			for(int i = 1; i <= nvertices; i++){
				edges[i] = NULL;
			}

			directed = dir;
}

void graph :: read_graph(){
	int x,y, ne;
	cout<<"Enter number of edges : ";
	cin>>ne;
	for(int i = 1; i <= ne; i++){
		cout<<"Enter edge "<<i<<" : ";
		cin>>x>>y;
		insert_edge(x,y, directed);
	}
}

void graph :: insert_edge(int x, int y, bool dir){
	vertex* p = new vertex;
	p->weight = 0;
	p->value = y;
	p->next = edges[x];
	edges[x] = p;
	degree[x]++;

	if(!dir){
		insert_edge(y, x, true);
	} else {
		nedges++;
	}
}

void graph :: print_graph(){
	vertex* p = new vertex;
	for(int i = 1; i <= nvertices; i++){
		cout<<i;
		p = edges[i];

		while(p!=NULL){
			cout<<" - "<<p->value;
			p = p->next;
		}


		cout<<endl;
	}
}




