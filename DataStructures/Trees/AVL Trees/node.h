/*
 * node.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>

using namespace std;

template<typename T>
class node{
	T value;
	node<T>* left;
	node<T>* right;
	node<T>* parent;

	public:
		node(T val) : value(val), left(NULL), right(NULL), parent(NULL){};
		T getValue(){ return value; }
		node<T>* getLeft(){ return left; }
		node<T>* getRight() { return right; }
		node<T>* getParent() { return parent; }

		void setValue(T val) { value = val;}
		void setLeft(node<T>* l){ left = l; }
		void setRight(node<T>* r){ right = r; }
		void setParent(node<T>* p){ parent = p; }
};


#endif /* NODE_H_ */
