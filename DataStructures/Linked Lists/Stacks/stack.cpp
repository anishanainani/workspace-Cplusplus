/*
 * stack_operations.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: Komani
 */

#include<iostream>
#include "stackElement.h"

using namespace std;

template<class T>
class stack{
	private:
		stackElement<T>* head;
	public:

	stack(){ head = NULL;};

	void push(T);

	T* pop();

	~stack();

};

template<class T>
void stack<T> :: push(T value){

	stackElement<T> *element = new stackElement<T>(value);
	if(!element){
		cout<<"Memory Allocation failed."<<endl;
		return;
	}

	element->setNext(head);
	element->setValue(value);
	head = element;
	cout<<value<<" Pushed."<<endl;
};

template<class T>
T* stack<T> :: pop(){
	if(!head){ //Empty Stack
		cout<<"Empty stack"<<endl;
		return NULL;
	}

	stackElement<T> *elem = head;
	T* data = new T;
	*data = elem->value();
	head = elem->next();
	delete elem;

	return data;
};

template<class T>
stack<T> :: ~stack(){

	stackElement<T> * elem = head;
	stackElement<T> * next;
	while(elem){
		next = elem->next();
		delete elem;
		elem = next;
	}

	head = NULL;
};



