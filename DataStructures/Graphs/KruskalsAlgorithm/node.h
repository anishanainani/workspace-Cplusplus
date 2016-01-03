/*
 * node.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Anisha
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>
#include<vector>

using namespace std;

class edge_node{
	int value;
	int weight;

	public:
		edge_node(int val, int w) : value(val), weight(w){};
		int getValue(){return value; }
		int getWeight() { return weight; }

		void setValue(int val){ value = val;}
		void setWeight(int w) { weight = w; }

};


#endif /* NODE_H_ */
