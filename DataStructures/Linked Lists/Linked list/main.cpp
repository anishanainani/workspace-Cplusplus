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

	listElement<int> *head;
	list<int> l(&head);

	l.insertInFront(3);
	l.insertInFront(1);
	l.insertInFront(3);
	l.insertInFront(1);
	l.insertInFront(0);

	/*
	for(int i = 0; i<9; i++){
		if(l.insertInFront(i)){
			cout<<"Insert successful."<<endl;
		} else {
			cout<<"Insert unsuccessful."<<endl;
		}
	}



	if(l.deleteElement(l.find( 4))){
		cout<<"Delete successful."<<endl;
	}else{
		cout<<"Delete unsuccessful."<<endl;
	}



	if(l.deleteElement(l.find( 4))){
		cout<<"Delete successful."<<endl;
	}else{
		cout<<"Delete unsuccessful."<<endl;
	}

	l.deleteList();
	if(!head) cout<<"List deleted."<<endl;
	*/
	l.removeDuplicates();

	while(head!=NULL){
		cout<<head->value()<<endl;
		head= head->getNext();
	}

	return 0;
}
