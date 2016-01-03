/*
 * main.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Anisha
 */

#include<iostream>
#include<vector>
#include "graph.h"
#include "BFS.cpp"

using namespace std;

int main(){
	vector<string> input;

	for(int i = 0; i < 5; ++i){
		char* in = new char[20];
		cout<<"Enter the vertex:"<<endl;
		cin.getline(in, 20);
		input.push_back(string(in));
	}

	graph<string> * g = new graph<string>(input, false);

	for(int i = 0; i < 5; ++i){
			int s, t;
			cout<<"Enter the edge:"<<endl;
			cin>>s;
			cin>>t;
			g->addEdge(s, t);
	}

	BFS<string> b(g);
	b.traverse(0);

	return 0;
}



