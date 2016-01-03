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
#include<fstream>
#include<string>


using namespace std;

int convertToInt(string &s){
	int n = 0;
	for(int i = 0; i < s.size(); ++i){
		n = n*10+int(s.at(i)-'0');
	}
	return n;
}

int main(){
	vector<int> input;
	ifstream f("graph.txt");
	if(f.fail()){
		cout<<"Fail"<<endl;
	}

	for(int i = 1; i <=84; ++i){
		input.push_back(i);
		//char* in = new char[20];
		//cout<<"Enter the vertex:"<<endl;
		//cin.getline(in, 20);
		//input.push_back(string(in));
	}


	graph<int> * g = new graph<int>(input, false);
	cout<<g->getNumberOfVertices()<<endl;
	while(f){
		string node1;
		f>>node1;
		string node2;
		f>>node2;
		string weight;
		f>>weight;
		/*
			int s, t;
			cout<<"Enter the edge:"<<endl;
			cin>>s;
			cin>>t;

			*/
		int s = convertToInt(node1);
		int t = convertToInt(node2);
		//cout<<s<<t;

		g->addEdge(s-1, t-1);
	}


	BFS<int> b(g);
	//b.traverse(0);

	//b.findShortestPath(0,4);
	b.connectedComponents();
	return 0;
}



