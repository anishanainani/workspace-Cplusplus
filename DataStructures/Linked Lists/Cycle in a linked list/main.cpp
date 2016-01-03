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

	l->formCycle();

	if(l->hasCycle()){
		cout<<"List is cyclic."<<endl;
	}
	return 0;
}
