/*
 * main.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "node.h"
#include "AVLTrees.h"

using namespace std;

int main(){

	AVLTrees<int> r;
	r.insertNode(9);
	r.insertNode(5);
	r.insertNode(3);
	r.insertNode(6);
	r.insertNode(10);
	r.insertNode(12);
	r.insertNode(15);
	r.inorder();
	return 0;
}


