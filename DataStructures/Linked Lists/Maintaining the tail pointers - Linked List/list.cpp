/*
 * list.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: Komani
 */

#include<iostream>
#include "listElement.h"

using namespace std;

template<class T>
class list{
	private:
		listElement<T> *head;
		listElement<T> *tail;
	public:
		list() : head(NULL), tail(NULL){};

		listElement<T> *getTail(){ return tail;};

		void insertInFront(T);

		void insertAfter(listElement<T>* ,T );

		void deleteElement(listElement<T> *);

		listElement<T> *find( T );

		~list();
};

template<class T>
void list<T> :: insertInFront(T value){

	listElement<T> *element = new listElement<T>(value);
	if(!element) {
		cout<<"Memory allocation failed."<<endl;
		return;
	}

	if(head == NULL){
		tail=element;
	}

	element->setNext(head);
	head = element;

	cout<<"Element Inserted in front"<<endl;
};

template<class T>
void list<T> :: insertAfter(listElement<T>* afterThis, T value){

	listElement<T> *element = new listElement<T>(value);
	if(!element){
		cout<<"Memory allocation failed."<<endl;
		return;
	}

	if(afterThis == NULL) {//Insert in front
		element->setNext(head);
		head = element;
		cout<<"Element Inserted in front"<<endl;
		if(!tail){ //for empty list
			tail = element;
		}
		return;
	}


	//inserting at end of list
	if(afterThis->getNext() == NULL){
		tail=element;
	}


	element->setNext(afterThis->getNext());
	afterThis->setNext(element);

	cout<<"Element inserted after "<<afterThis->value()<<endl;

};


template<class T>
void list<T> :: deleteElement(listElement<T> *deleteMe){

	if(!head){
		cout<<"List is Empty"<<endl;
		return;
	}

	if(!deleteMe){
		cout<<"Element passed is NULL."<<endl;
		return;
	}


	listElement<T> *elem = head;

	//special case for first element
	if(deleteMe == elem){
		head = deleteMe->getNext();
		delete deleteMe;
		tail = NULL;
		return;
	}

	while(elem){
		if(elem->getNext()==deleteMe){
			if(deleteMe == tail){
				tail = elem;
			}
			elem->setNext(deleteMe->getNext());
			delete deleteMe;
			cout<<"Element deleted successfully."<<endl;
			return;
		}
		elem = elem->getNext();
	}

	cout<<"Element not found."<<endl;
};

template<class T>
list<T> :: ~list(){

	listElement<T> * elem = head;
	listElement<T> * next;
	while(elem){
		next = elem->getNext();

		elem = next;
	}

	head = NULL;
	tail = NULL;
	cout<<"List deleted."<<endl;
};

template<class T>
listElement<T>* list<T> :: find(T value){
	listElement<T>* elem = head;
	while(elem!=NULL && elem->value() != value){
		cout<<elem->value()<<" ";
		elem = elem->getNext();
	}

	return elem;
};
