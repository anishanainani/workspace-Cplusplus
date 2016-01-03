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

	listElement<int>* f= l->getMthLastElement(10);
	if(f) cout<<f->value();
	return 0;
}
