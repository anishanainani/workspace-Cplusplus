/*
 * binaryTree.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Komani
 */

#include<iostream>

#include "Node.h"
#include<math.h>
#include "stackNode.cpp"

using namespace std;

template<class T>
class binaryTree{
	private:
		Node<T>* root;

	public:
		binaryTree<T>() : root(NULL) {};

		Node<T>* getRoot() { return root; }
		void insertNode(T);
		void deleteNode(Node<T>*);
		Node<T>* findNode(T);
		void deleteTree(Node<T>*);

		void  preorderTraversal();

		~binaryTree<T>();

};

template<class T>
void binaryTree<T> :: insertNode(T value){
	Node<T>* curNode = root;
	Node<T>* newNode = new Node<T>(value);
	if(!newNode){
		cout<<"Memory Allocation failed."<<endl;
		return;
	}

	if(!root){
			root = newNode;
			return;
	}

	while(true){
		if(curNode->getValue() < value){
			if(!curNode->getRight()) {
				curNode->setRight(newNode);
				break;
			}
			curNode = curNode->getRight();
		} else {
			if(!curNode->getLeft()){
				curNode->setLeft(newNode);
				break;
			}
			curNode = curNode->getLeft();
		}
	}


};

template<class T>
void  binaryTree<T> :: deleteNode(Node<T>* deleteMe){

}

template<class T>
Node<T>*  binaryTree<T> ::findNode(T value){
	Node<T>* curNode = root;

	while(true){
		if(!curNode) return NULL;

		if(curNode->getValue() == value) return curNode;
		if(curNode->getValue() < value){
			curNode = curNode->getRight(); // findNode(curNode->getRight(), value);
		} else {
			curNode = curNode->getLeft(); // findNode(curNode->getLeft(), value);
		}
	}
}


template<class T>
void binaryTree<T> :: preorderTraversal(){
	if(root == NULL){
		cout<<"Tree is empty."<<endl;
		return;
	}
	stackNode<T>* s = new stackNode<T>();
	Node<T>* curNode = root;
	s->push(curNode);
	while(s->size() > 0){
		curNode = s->pop();
		cout<<curNode->getValue()<<endl;
		if(curNode->getRight()) s->push(curNode->getRight());
		if(curNode->getLeft()) s->push(curNode->getLeft());
	}
}


template<class T>
binaryTree<T> :: ~binaryTree(){

	deleteTree(root);
	root = NULL;
};

template<class T>
void binaryTree<T> :: deleteTree(Node<T>* start){
	if(start != NULL){

	deleteTree(start->getLeft());
	deleteTree(start->getRight());
	delete start;
	}
};

