/*
 * main.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#include<iostream>
#include "Permutations.h"

using namespace std;

void printAllPermutations(string soFar, string rest){
	if(rest == ""){
		cout<<soFar<<endl;
		return;
	}

	for(int i = 0; i < rest.length(); ++i){
		printAllPermutations(soFar+rest.at(i), rest.substr(0, i)+rest.substr(i+1));
	}
};

void doPrintAllPermutations(const string input){
	printAllPermutations("", input);
}

int main(){
	//doPrintAllPermutations("abcd");
	Permutations p("abcd");
	p.permute();
	return 0;
}


