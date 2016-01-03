/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

bool isAnagram(string& s, string& t){

	if(s.size() != t.size()) return false;
	int* characters = new int[256];

	for(unsigned i = 0; i < 256; ++i){
			characters[i] = 0;
	}

	int num_unique_s = 0;
	int num_unique_t = 0;
	for(unsigned i = 0; i < s.size(); ++i){
		int val = (int)s.at(i);
		if(characters[val] == 0) {
			++num_unique_s;
		}
		++characters[val];
	}


	for(unsigned i = 0; i < t.size(); ++i){
		int val = (int)t.at(i);
		if(characters[val] == 0) return false;
		--characters[val];

		if(characters[val] == 0){
			++num_unique_t;

			if(num_unique_s == num_unique_t){
				return (i==(t.size()-1));
			}
		}
	}

	return false;
}

int main(){

	string s, t;
	cin>>s;
	cin>>t;

	if(isAnagram(s, t)){
		cout<<"Strings are anagrams"<<endl;
	} else {
		cout<<"Strings are not anagrams"<<endl;
	}
	return 0;
}


