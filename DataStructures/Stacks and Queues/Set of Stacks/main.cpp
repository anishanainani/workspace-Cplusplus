/*
 * main.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include "setOfStacks.h"

using namespace std;

int main(){

	setOfStacks s1;
	s1.push(5);
	s1.push(7);
	s1.push(1);
	s1.push(6);
	s1.push(9);
	s1.push(0);
	s1.push(4);
	s1.push(3);


	cout<<s1.popAt(0)<<endl;
	cout<<s1.pop()<<endl;


	return 0;
}



