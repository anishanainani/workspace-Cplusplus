/*
 * stackWithMin.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include "stackWithMin.h"
#include <limits>

using namespace std;

void stackWithMin :: push(int value){
	if(top == MAXSIZE-1){
		cout<<"Error : Stack Overflow"<<endl;
	}

	stack[++top] = value;

	if(value < min()){
		minValues.push_back(value);
	}
};

int stackWithMin :: pop(){
	if(top == -1){
		cout<<"Error : Stack Underflow"<<endl;
	}

	if(stack[top] == min()){
		minValues.pop_back();
	}
	return stack[top--];
};

int stackWithMin :: min(){
	if(minValues.empty()){
		return std::numeric_limits<int>::max();
	} else {
		return minValues.back();
	}
};

