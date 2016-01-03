/*
 * main.cpp
 *
 *  Created on: Feb 8, 2015
 *      Author: Komani
 */

#include<iostream>
#include "binaryTree.cpp"


using namespace std;

int main(){

	binaryTree<int>* t  = new binaryTree<int>;

	int numbers[] = {20, 8, 22, 4, 12, 21, 23, 19, 24, 28};
	for(int i = 0; i < 10; i++){
			t->insertNode(numbers[i]);
	}

	t->makeListsAtEachLevel();

	return 0;
}


