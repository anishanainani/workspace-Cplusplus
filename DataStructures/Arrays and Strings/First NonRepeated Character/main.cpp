/*
 * main.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: Komani
 */

#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

char firstNonRepeatedCharacter(string input){

	map< char, int > letterCountMap;

	for(int i = 0; i < input.size(); i++){
		if(letterCountMap.find(input.at(i))!=letterCountMap.end()){
			++letterCountMap[input.at(i)];
		} else {
			letterCountMap[input.at(i)] = 1;
		}
	}

	for(map< char, int >::iterator itr = letterCountMap.begin(); itr!=letterCountMap.end(); ++itr){
		if(letterCountMap[(*itr).first] ==1){
			return (*itr).first;
		}
	}

	return '\0';
};


int main(){
	cout<<firstNonRepeatedCharacter("teetletlr");
	return 0;
}


