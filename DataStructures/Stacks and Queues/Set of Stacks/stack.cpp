/*
 * stack.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include "stack.h"
#include <limits>

using namespace std;

bool stack :: push(int value){
	if(top == MAXSIZE-1){
		return false;
	}

	stackValues[++top] = value;
	return true;
};

bool stack :: pop(int & data){
	if(top == -1){
		cout<<"Error : Stack Underflow"<<endl;
		return false;
	}
	data = stackValues[top--];
	return true;
};





