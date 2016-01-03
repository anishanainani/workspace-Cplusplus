/*
 * node.h
 *
 *  Created on: Mar 13, 2015
 *      Author: Anisha
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>
#include "color.h"
using namespace std;

template<typename T>
class node{
	public:

		node(T val, nodeColor::color c) :  value(val), left(NULL), right(NULL), parent(NULL), nColor(c){};
		node(node<T>& copy) : value(copy.getValue()), left(copy.getLeft()), right(copy.getRight()), parent(copy.getParent()), nColor(copy.getColor()){};
		T getValue(){ return value; }
		node<T>* getLeft() { return left; }
		node<T>* getRight() { return right; }
		node<T>* getParent() { return parent; }
		nodeColor::color getColor() { return nColor; }
		bool operator!=(node<T>* other){ return value != other->getValue(); }
		bool operator==(node<T>* other){ return value == other->getValue(); }

		void setValue(T val){ value = val; }
		void setLeft(node<T>* l) { left = l; }
		void setRight(node<T>* r) { right = r; }
		void setParent(node<T>* p) { parent = p; }
		void setColor(nodeColor::color c) { nColor = c; }

	private:
		T value;
		node* left;
		node* right;
		node* parent;
		nodeColor::color nColor;

};


#endif /* NODE_H_ */
