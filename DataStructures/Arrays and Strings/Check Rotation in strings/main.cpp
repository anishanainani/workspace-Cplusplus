/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

bool isRotation(string s1, string s2){
	if((s1.size() != s2.size()) && s2.size() == 0 && s1.size() == 0){
		return false;
	}

	string s1s1 = s1+s1;

	return isSubstring(s2, s1s1);
}

int main(){
	return 0;
}


