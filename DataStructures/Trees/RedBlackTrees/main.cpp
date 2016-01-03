/*
 * main.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "node.h"
#include "color.h"
#include "rb-trees.h"

using namespace std;

int main(){
	node<int> n(5, nodeColor::RED);

	//cout<<(n.getColor()==0 ? "RED" : "BLACK") ;

	// Passing nil/leaf sentinel = -1, root sentinel = 0
	rbTrees<int> r(-1, 0);
	r.insertNode(9);
	r.insertNode(5);
	r.insertNode(3);
	r.insertNode(6);
	r.insertNode(13);
	r.insertNode(12);
	r.insertNode(14);

	r.inorder();
	return 0;
}


