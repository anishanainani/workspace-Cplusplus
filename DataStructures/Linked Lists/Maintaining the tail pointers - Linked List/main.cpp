/*
 * main.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: Komani
 */


#include<iostream>
#include "listElement.h"
#include "list.cpp"

using namespace std;

int main(){

	list<int>* l = new list<int>;

	for(int i = 0; i<9; i++){
		l->insertInFront(i);
	}

	l->find(0);
	cout<<endl;

	listElement<int>* t = l->getTail();

	l->insertAfter(t, 15);

	//to check tail pointer
	if(!l->find(15))
	l->deleteElement(l->find(15));
	else
		cout<<"Element cannot be found"<<endl;

	t = l->getTail();
	cout<<t->value();
	l->find(15);

	return 0;
}
