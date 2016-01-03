/*
 * graph.h
 *
 *  Created on: Jan 8, 2015
 *      Author: Komani
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>

using namespace std;

typedef struct v{
	int value;;
	int weight;
	struct v* next;
} vertex;

class graph{
	public:
		int nvertices;
		int nedges;
		int *degree;
		vertex** edges;
		bool directed;

	public:
		graph();
		graph(int nv,bool dir);

		void read_graph();
		void insert_edge(int, int, bool);
		void print_graph();
};


#endif /* GRAPH_H_ */
