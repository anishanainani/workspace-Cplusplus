/*
 * list.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: Komani
 */

#include<iostream>
#include "listElement.h"
#include<set>

using namespace std;

template<class T>
class list{
	public:
	list() : head(NULL){};
	list(listElement<T>** h) : head(*h){};

		bool insertInFront( T value);

		bool deleteElement(listElement<T> *deleteMe);

		void deleteList();

		listElement<T> *find( T value);

		bool removeDuplicates();

		void setHead(listElement<T> h){ head = h;}

	private:
		listElement<T>* head;
};

template<class T>
bool list<T> :: insertInFront( T value){

	listElement<T> *element = new listElement<T>(value);
	element->setNext(head);
	head = element;

	return true;
};

template<class T>
bool list<T> :: deleteElement(listElement<T> *deleteMe){
	if(!head || !deleteMe) return false;

	listElement<T> *elem = head;

	//special case for first element
	if(deleteMe == elem){
		head = deleteMe->getNext();

		return true;
	}

	while(elem){
		if(elem->getNext()==deleteMe){
			elem->setNext(deleteMe->getNext());

			return true;
		}
		elem = elem->getNext();
	}

	return false;
};

template<class T>
void list<T> :: deleteList(){

	listElement<T> * elem = head;
	listElement<T> * next;
	while(elem){
		next = elem->getNext();
		delete(elem);
		elem = next;
	}

	head = NULL;
};

template<class T>
listElement<T>* list<T> :: find(T value){
	listElement<T>* elem = head;
	while(elem!=NULL && elem->value() != value){
		elem = elem->getNext();
	}

	return elem;
};

template<class T>
bool list<T> :: removeDuplicates(){
	if(!head) return false;
	listElement<T>* curElem = head;

	set<T> elementsEncountered;

	while(curElem){
		listElement<T>* next = curElem->getNext();
		if(elementsEncountered.find(curElem->value()) != elementsEncountered.end()){
			elementsEncountered.insert(curElem->value());
		} else {
			deleteElement(curElem);
		}

		curElem = next;
	}

	return true;
};

