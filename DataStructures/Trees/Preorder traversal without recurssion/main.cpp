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

	binaryTree<int>* t  = new binaryTree<int>;

	int numbers[] = {9, 6, 10, 7, 5, 19, 8};
	for(int i = 0; i < 7; i++){
		t->insertNode(numbers[i]);
	}

	//cout<<t->getHeight();


	t->preorderTraversal();

	/*
	cout<<t->getRoot()->getValue();
	cout<<t->getRoot()->getLeft()->getValue();
	cout<<t->getRoot()->getRight()->getValue();
	cout<<t->getRoot()->getRight()->getRight()->getValue();
	cout<<t->getRoot()->getLeft()->getRight()->getValue();
	*/

	//cout<<t->findNode(10)->getRight()->getValue();
	return 0;
}


