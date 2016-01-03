/*
 * AVLTrees.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#ifndef AVLTREES_H_
#define AVLTREES_H_

#include<iostream>
#include "node.h"
#include<cmath>
using namespace std;

template<typename T>
class AVLTrees{
	node<T>* root;

	public:
		AVLTrees() : root(NULL){};
		node<T>* balancing(node<T>*);
		node<T>* insertNodeHelper(node<T>*,node<T>*,T);
		node<T>* leftRotate(node<T>*);
		node<T>* rightRotate(node<T>*);
		int nodeHeight(node<T>*);
		int childrenHeightDifference(node<T>*);
		void insertNode(T);
		void deleteNode(T);
		void inorder();
		void inorderHelper(node<T>*);
};

template<typename T>
int AVLTrees<T> :: nodeHeight(node<T>* elem){
	if(elem==NULL){ return -1; }
	return 1 + fmax(nodeHeight(elem->getLeft()), nodeHeight(elem->getRight()));
}

template<typename T>
int AVLTrees<T> :: childrenHeightDifference(node<T>* elem){
	int leftHeight = elem->getLeft()==NULL? -1 : nodeHeight(elem->getLeft());
	int rightHeight = elem->getRight()==NULL? -1 : nodeHeight(elem->getRight());

	return leftHeight-rightHeight;
}

template<typename T>
node<T>* AVLTrees<T> :: leftRotate(node<T>* x){
	node<T>* y = x->getRight();
	x->setRight(y->getLeft());

	if(y->getLeft() !=NULL)
		y->getLeft()->setParent(x);

	y->setParent(x->getParent());

	if(x->getParent() == NULL){
		root = y;
	} else if(x==x->getParent()->getLeft()){
		x->getParent()->setLeft(y);
	}else {
		x->getParent()->setRight(y);
	}
	y->setLeft(x);
	x->setParent(y);
	return y;
}

template<typename T>
node<T>* AVLTrees<T> :: rightRotate(node<T>* x){
	node<T>* y = x->getLeft();
	x->setLeft(y->getRight());

	if(y->getRight()!=NULL)
		y->getRight()->setParent(x);

	y->setParent(x->getParent());

	if(x->getParent() == NULL){
		root = y;
	} else if(x==x->getParent()->getLeft()){
		x->getParent()->setLeft(y);
	}else {
		x->getParent()->setRight(y);
	}
	y->setRight(x);
	x->setParent(y);

	return y;
}

template<typename T>
node<T>* AVLTrees<T> :: balancing(node<T>* elem){
	int diff = childrenHeightDifference(elem);

	if(diff > 1){
		if(childrenHeightDifference(elem->getLeft()) < 0){
			leftRotate(elem->getLeft());
		}

		elem = rightRotate(elem);

	} else if(diff < -1) {
		if(childrenHeightDifference(elem->getRight()) > 0){
			rightRotate(elem->getRight());
		}

		elem = leftRotate(elem);
	}

	return elem;

}

template<typename T>
void AVLTrees<T> :: insertNode(T value){

	root = insertNodeHelper(root,NULL, value);


}

template<typename T>
node<T>* AVLTrees<T> :: insertNodeHelper(node<T>* elem, node<T>* parent,T value){

	if(elem == NULL){

		node<T>* newNode = new node<T>(value);

		if(!newNode){
			cout<<"Memory allocation failed"<<endl;
			return NULL;
		}

		newNode->setParent(parent);

		return newNode;
	} else if(value < elem->getValue()){
		elem->setLeft(insertNodeHelper(elem->getLeft(),elem, value));
		elem = balancing(elem);

	} else {
		elem->setRight( insertNodeHelper(elem->getRight(), elem,value));
		elem = balancing(elem);
	}

	return elem;

}

template<typename T>
void AVLTrees<T> :: inorderHelper(node<T>* n){
	if(n!=NULL){
		inorderHelper(n->getLeft());
		cout<<n->getValue()<<"-"<<nodeHeight(n);
		cout<<endl;
		inorderHelper(n->getRight());
	}
}

template<typename T>
void AVLTrees<T> :: inorder(){
	inorderHelper(root);
}



#endif /* AVLTREES_H_ */
