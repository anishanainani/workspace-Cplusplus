/*
 * stack.h
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#ifndef STACK_H_
#define STACK_H_

#include<iostream>
#include<vector>

using namespace std;

class stack{

	public:
		stack(int maxSize) : MAXSIZE(maxSize), top(-1){ stackValues = new int[MAXSIZE];}
		bool push(int value);
		bool pop(int&);

	private:
		int MAXSIZE;
		int* stackValues;
		int top;
};



#endif /* STACK_H_ */
