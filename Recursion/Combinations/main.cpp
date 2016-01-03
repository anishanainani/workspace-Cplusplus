/*
 * main.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#include<iostream>
#include "Combinations.h"

using namespace std;

void combine(string soFar, string rest){
	if(rest == ""){
		cout<<soFar<<endl;
		return;
	}else {
		combine(soFar+rest.at(0), rest.substr(1));
		combine(soFar, rest.substr(1));
	}
};

int main(){
	//combine("", "abcd");
	Combinations c("abcd");
	c.combine();
	return 0;
}


