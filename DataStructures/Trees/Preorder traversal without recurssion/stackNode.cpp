/*
 * stack.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>
#include "Node.h"

using namespace std;

template<class T>
class stackNode{
	private:
		vector<Node<T>*> stack;
	public:
		stackNode(){};
		void push(Node<T>*);
		Node<T>* pop();
		int size(){ return stack.size(); };
		~stackNode(){};
};

template<class T>
void stackNode<T> :: push(Node<T>* elem){
	stack.push_back(elem);
}

template<class T>
Node<T>* stackNode<T> :: pop(){
	if(stack.size() < 1){
		cout<<"Stack is empty."<<endl;
		return NULL;
	}

	Node<T>* toBePopped = stack[stack.size()-1];
	stack.pop_back();
	return toBePopped;
}
