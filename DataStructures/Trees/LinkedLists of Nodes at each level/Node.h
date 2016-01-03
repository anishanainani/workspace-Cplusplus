/*
 * Node.h
 *
 *  Created on: Jan 16, 2015
 *      Author: Komani
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>

using namespace std;

template<class T>
class Node{
	private:
		Node* left;
		Node* right;
		T value;
		Node* parent;

	public:
		Node() {};
		Node(const T & data) : left(NULL), right(NULL),parent(NULL), value(data){};
		Node(Node* l, Node* r, const T &data) : left(l), right(r), value(data){};
		Node* getLeft() { return left; }
		Node* getRight() { return right; }
		Node* getParent() { return parent; }
		T getValue() { return value; }
		void setLeft(Node* l) { left = l; }
		void setRight(Node* r) { right = r; }
		void setParent(Node* p) { parent = p; }
		void setValue(const T& data) { value = data; }
		~Node(){}
};


#endif /* NODE_H_ */
