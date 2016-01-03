/*
 * rb-trees.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#ifndef RB_TREES_H_
#define RB_TREES_H_

#include<iostream>
#include "color.h"
using namespace std;

template<typename T>
class rbTrees{
	node<T>* root;
	node<T>* nil;
	T nil_sentinel;
	T root_sentinel;

	public:
		rbTrees() : root(NULL), nil(NULL){};
		rbTrees(T, T);
		void leftRotate(node<T>*);
		void rightRotate(node<T>*);
		void insertNode(T);
		node<T>* insertNodeHelper(T);
		void inorderHelper(node<T>*);
		void inorder();
};

template<typename T>
rbTrees<T> :: rbTrees(T l, T r) : nil_sentinel(l), root_sentinel(r){

	nil = new node<T>(nil_sentinel, nodeColor::BLACK);
	nil->setLeft(nil);
	nil->setRight(nil);
	nil->setParent(nil);

	root = new node<T>(root_sentinel, nodeColor::BLACK);
	root->setLeft(nil);
	root->setRight(nil);
	root->setParent(nil);
};

template<typename T>
void rbTrees<T> :: leftRotate(node<T>* x){
	node<T>* y = x->getRight();
	x->setRight(y->getLeft());

	if(y->getLeft() !=nil)
		y->getLeft()->setParent(x);

	y->setParent(x->getParent());

	if(x->getParent() == root){
		root->setLeft(y);
	} else if(x==x->getParent()->getLeft()){
		x->getParent()->setLeft(y);
	}else {
		x->getParent()->setRight(y);
	}
	y->setLeft(x);
	x->setParent(y);

}

template<typename T>
void rbTrees<T> :: rightRotate(node<T>* x){
	node<T>* y = x->getLeft();
	x->setLeft(y->getRight());

	if(y->getRight()!=nil)
		y->getRight()->setParent(x);

	y->setParent(x->getParent());

	if(x->getParent() == root){
		root->setLeft(y);
	} else if(x==x->getParent()->getLeft()){
		x->getParent()->setLeft(y);
	}else {
		x->getParent()->setRight(y);
	}
	y->setRight(x);
	x->setParent(y);

}

template<typename T>
node<T>* rbTrees<T> :: insertNodeHelper(T insertValue){
	node<T>* rootNode = root->getLeft();
	node<T>* parentNode = root;
	node<T>* newNode = new node<T>(insertValue, nodeColor::RED);
	newNode->setLeft(nil);
	newNode->setRight(nil);

	while(rootNode!=nil){
		parentNode = rootNode;
		if(insertValue < rootNode->getValue()){
			rootNode = rootNode->getLeft();
		}else {
			rootNode = rootNode->getRight();
		}
	}

	newNode->setParent(parentNode);
	if(parentNode == root){

		root->setLeft(newNode);
	} else if(insertValue < parentNode->getValue()){
		parentNode->setLeft(newNode);
	} else {
		parentNode->setRight(newNode);
	}

	return newNode;
}

template<typename T>
void rbTrees<T> :: insertNode(T insertValue){
	node<T>* x = insertNodeHelper(insertValue);

	while(x!=root && x->getParent()->getColor() == nodeColor::RED){

		if(x->getParent() == x->getParent()->getParent()->getLeft()){
			node<T>* y = x->getParent()->getParent()->getRight();
			if(y->getColor() == nodeColor::RED){	//Case 1
				y->setColor(nodeColor::BLACK);
				x->getParent()->setColor(nodeColor::BLACK);
				x->getParent()->getParent()->setColor(nodeColor::RED);
				x = x->getParent()->getParent();
			} else {
				if(x == x->getParent()->getRight()){	//Case 2
					x = x->getParent();
					leftRotate(x);
				}
				//Case 3
				x->getParent()->setColor(nodeColor::BLACK);
				x->getParent()->getParent()->setColor(nodeColor::RED);
				if(x->getParent()->getParent() != root)
				rightRotate(x->getParent()->getParent());
			}
		} else {
			node<T>* y = x->getParent()->getParent()->getLeft();
			if(y->getColor() == nodeColor::RED){	//Case 1
				y->setColor(nodeColor::BLACK);
				x->getParent()->setColor(nodeColor::BLACK);
				x->getParent()->getParent()->setColor(nodeColor::RED);
				x = x->getParent()->getParent();
			} else {
				if(x == x->getParent()->getLeft()){	//Case 2
					x = x->getParent();
					rightRotate(x);
				}
			//Case 3
				x->getParent()->setColor(nodeColor::BLACK);
				x->getParent()->getParent()->setColor(nodeColor::RED);
				if(x->getParent()->getParent() != root)
				leftRotate(x->getParent()->getParent());
			}
		}

		root->setColor(nodeColor::BLACK);
	}
}

template<typename T>
void rbTrees<T> :: inorderHelper(node<T>* n){
	if(n!=nil){

		inorderHelper(n->getLeft());
		cout<<n->getValue()<<"-"<<(n->getColor()==0?"RED":"BLACK");
		cout<<endl;
		inorderHelper(n->getRight());

	}
}

template<typename T>
void rbTrees<T> :: inorder(){
	inorderHelper(root->getLeft());
}
#endif /* RB_TREES_H_ */
