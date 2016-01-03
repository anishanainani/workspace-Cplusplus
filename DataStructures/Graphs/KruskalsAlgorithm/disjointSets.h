/*
 * disjointSets.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Anisha
 */

#ifndef DISJOINTSETS_H_
#define DISJOINTSETS_H_

#include<iostream>
#include<unordered_map>

using namespace std;

class disjointSets{
	unordered_map<char, char> parent;
	unordered_map<char,int> rank;

	public:
		disjointSets(){};
		void makeSet(char);
		char find(char);
		void unionSets(char,char);
		void display();
};


void disjointSets :: display(){
	for(typename unordered_map<char, char> :: iterator it = parent.begin(); it!=parent.end(); ++it){
		cout<<(*it).first<<" "<<(*it).second;
				cout<<endl;
	}
}

void disjointSets :: makeSet( char node){
	parent[node] = node;
	rank[node] = 0;
}

char disjointSets :: find(char ch){
	if(parent[ch] == ch){
		return ch;
	} else {
	 return find(parent[ch]);
	}
}

void disjointSets :: unionSets(char set1,char set2){
	char s1 = find(set1);
	char s2 = find(set2);
	if(rank[s1] > rank[s2]){
		parent[s2] = s1;
	} else if(rank[s1] < rank[s2]){
		parent[s1] = s2;
	} else {
		parent[s1] = s2;
		++rank[s2];
	}
}
#endif /* DISJOINTSETS_H_ */
