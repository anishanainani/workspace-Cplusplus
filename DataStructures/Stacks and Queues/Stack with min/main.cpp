/*
 * main.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Komani
 */

#include<iostream>
#include "stackWithMin.h"

using namespace std;

int main(){

	stackWithMin s1;
	s1.push(5);
	s1.push(7);
	s1.push(1);
	s1.push(6);

	cout<<s1.min()<<endl;

	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;

	cout<<s1.min()<<endl;
	return 0;
}
