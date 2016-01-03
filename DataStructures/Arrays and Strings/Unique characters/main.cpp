/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

int main(){

	string input;
	cin>>input;

	//1st approach O(n)
	bool* characters = new bool[256];
	for(unsigned i = 0; i < 256; ++i){
		characters[i] = false;
	}

	for(unsigned i = 0; i < input.length(); ++i){
		int ascii = (int)input.at(i);
		if(characters[ascii]){
			//cout<<"All characters aren't unique"<<endl;
			//return 0;
		}
		characters[ascii] = true;
	}

	//cout<<"All unique characters"<<endl;

	//2nd approach - reduced space complexity
	int checker = 0;
	for(unsigned i = 0; i < input.length(); ++i){
			int ascii = (int)input.at(i);
			if((checker & (1<<ascii)) > 0){
				cout<<"All characters aren't unique"<<endl;
				return 0;
			}

			checker|=(1<<ascii);
	}

	cout<<"All unique characters"<<endl;
	return 0;
}


