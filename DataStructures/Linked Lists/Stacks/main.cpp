/*
 * main.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: Komani
 */

/*
 * main.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: Komani
 */
#include<iostream>
#include "stackElement.h"
#include "stack.cpp"

using namespace std;

int main(){

	stack<int>* s = new stack<int>;

	for(int i = 0; i < 5; i++){
		s->push(i);
	}

	delete s;
	for(int i = 0; i < 5; i++){
		int* data = s->pop();
		if(data!=NULL){
			cout<<*data<<" Popped."<<endl;
		}
	}


	return 0;
}





