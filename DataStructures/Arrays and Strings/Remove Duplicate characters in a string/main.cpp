/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

void removeDuplicates(string& input){
	int checker = 0;

	unsigned i = 0;
	while(i<input.length()){
		int val = (int)input.at(i) - 'a';
		if((checker & (1<<val)) > 0){
			input = input.substr(0, i)+input.substr(i+1);
		} else{
			++i;

		}
		checker|=(1<<val);
	}
};

int main(){
	string input = "aaakomal";
	removeDuplicates(input);

	cout<<input;
	return 0;
}


