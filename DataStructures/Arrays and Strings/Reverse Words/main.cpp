/*
 * main.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

string reverseWords(string input){
	string result;

	for(int i = 0; i < input.length();){
		string temp = "";
		while(input[i] != ' ' && input[i] != '\n'){
			temp+=input[i];
			++i;
		}
		++i;

		result = temp+' '+result;
	}

	return result;
};


int main(){
	cout<<reverseWords("My name is anisha.\n");
	return 0;
}


