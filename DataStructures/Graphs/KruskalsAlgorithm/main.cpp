/*
 * main.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "disjointSets.h"
#include<vector>
#include "kruskals.h"

using namespace std;

int main(){

	/* Testing disjoint sets
	disjointSets d;
	d.makeSet('a');
	d.makeSet('b');
	d.makeSet('c');
	d.makeSet('d');
	d.makeSet('e');

	cout<<d.find('c')<<endl;

	d.unionSets('a', 'b');
	d.unionSets('c', 'd');
	d.unionSets('a', 'd');
	d.unionSets('e', 'a');

	d.display();
	*/

	vector<char> input;

	for(int i = 0; i < 4; ++i){
		char ch;
		cout<<"Enter the vertex(character):"<<endl;
		cin>>ch;
		input.push_back(ch);
	}

	graph<char> * g = new graph<char>(input, false);

	for(int i = 0; i < 5; ++i){
		int s, t, w;
		cout<<"Enter the edge and weight:"<<endl;
		cin>>s;
		cin>>t;
		cin>>w;
		g->addEdge(s, t, w);
	}

	kruskals k(g);
	k.findMST();
	return 0;
}


