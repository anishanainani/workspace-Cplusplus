/*
 * stackWithMin.h
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#ifndef STACKWITHMIN_H_
#define STACKWITHMIN_H_

#include<iostream>
#include<vector>

using namespace std;

class stackWithMin{

	public:
		stackWithMin() : top(-1), minTop(-1){ stack = new int[MAXSIZE];}
		void push(int value);
		int pop();
		int min();
	private:
		int const MAXSIZE = 20;
		int* stack;
		int top, minTop;
		vector<int> minValues;
};


#endif /* STACKWITHMIN_H_ */
