/*
 * main.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Komani
 */
#include<iostream>
#include "binaryTree.cpp"
#include "Node.h"


using namespace std;

int main(){

	binaryTree<long>* t  = new binaryTree<long>;
	t->insertNode();
	//t->inorder();
	cout<<t->findMaxSum();

	return 0;
}
