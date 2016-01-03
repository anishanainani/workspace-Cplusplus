/*
 * setOfStacks.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include "setOfStacks.h"

using namespace std;

void setOfStacks :: push(int value){
	if(!stacks[currentStack].push(value)){
		stacks.push_back(stack(MAXSIZE));
		++currentStack;
		stacks[currentStack].push(value);
	}
}

int setOfStacks :: popAt(int index){
		int value;
		if(!stacks[index].pop(value)){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}
		return value;
}

int setOfStacks :: pop(){
		int value;
		if(currentStack==-1){
			cout<<"Stack Underflow"<<endl;
			return -1;
		}

		if(!stacks[currentStack].pop(value)){
				stacks.pop_back();
				--currentStack;
				pop();
				return -1;
		}

		return value;
}