/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

void replaceSpaces(string & input){
	for(unsigned i = 0; i < input.size(); ++i){
		if(input[i] == ' '){
			input = input.substr(0, i)+"%20"+input.substr(i+1);
			i+=2;
		}
	}
}

int main(){
	string input("anisha komal hema indu");

	replaceSpaces(input);
	cout<<input;
	return 0;
}

