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
	public:
		list() : head(NULL){};

		void insertInFront(T);

		void deleteElement(listElement<T> *);

		listElement<T>* getMthLastElement(int);

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

	element->setNext(head);
	head = element;

	cout<<"Element Inserted in front"<<endl;
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

		return;
	}

	while(elem){
		if(elem->getNext()==deleteMe){

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

template<class T>
listElement<T>* list<T> :: getMthLastElement(int m){
	if(!head){
		cout<<"Empty List."<<endl;
		return NULL;
	}

	listElement<T>* elem = head;
	for(int i = 1; i < m; i++){
		if(elem->getNext()){
			elem = elem->getNext();
		} else {
			cout<<"m > length of linked list."<<endl;
			return NULL;
		}
	}

	listElement<T>* mBehind = head;
	while(elem->getNext() != NULL){
		elem=elem->getNext();
		mBehind=mBehind->getNext();
	}

	return mBehind;
};

