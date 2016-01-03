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

	int numbers[] = {20, 8, 22, 4, 12, 21, 23, 19, 24, 28};
	for(int i = 0; i < 10; i++){
		t->insertNode(numbers[i]);
	}

	//Node<int>* result = t->lowestCommonAncestor(t->findNode(4), t->findNode(8));
	//if(result){

		//cout<<result->getValue();}

	//if(t->isBalanced()) cout<<"Balanced"<<endl;
	//else cout<<"Not Balanced";


	//cout<<t->getHeight();

	//t->preorder();
	//t->inorder();
	//t->postorder();
	/*
	cout<<t->getRoot()->getValue();
	cout<<t->getRoot()->getLeft()->getValue();
	cout<<t->getRoot()->getRight()->getValue();
	cout<<t->getRoot()->getRight()->getRight()->getValue();
	cout<<t->getRoot()->getLeft()->getRight()->getValue();
	*/

	//cout<<t->findNode(10)->getRight()->getValue();

	//if(t->findNode(22)) cout<<"22 exists"<<endl;
	//Node<int>* p = t->findNode(22)->getParent();

	//t->deleteNode(t->findNode(22));

	//cout<<p->getRight()->getValue()<<endl;

	//if(!t->findNode(22)) cout<<"22 doesnt exist"<<endl;

	if(t->inorderSuccessor(t->findNode(19))){
		cout<<t->inorderSuccessor(t->findNode(19))->getValue();
	}


	return 0;
}


