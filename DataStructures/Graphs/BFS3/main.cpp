/*
 * main.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: Komani
 */

#include<iostream>
#include "graph.h"
#include "BFS.cpp"

using namespace std;

int main(){

	graph g(6, false);
	g.read_graph();
	g.print_graph();
	BFS b(g);
	b.bfs_traversal(1);
	//b.connected_components();
	cout<<"end";
	b.find_path(1,6);
	return 0;
}



