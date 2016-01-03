/*
 * main.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

string removeChars(string input, string remove){
	bool* flags = new bool[128];

	for(int i = 0; i < remove.length(); i++){
		flags[(int)remove[i]] = true;
	}

	string result;

	for(int i = 0; i < input.length(); i++){
			if(!flags[(int)input[i]]){
				result+=input[i];
			}
	}


	return result;
};


int main(){
	cout<<removeChars("My name is anisha.", "aeiou");
	return 0;
}


