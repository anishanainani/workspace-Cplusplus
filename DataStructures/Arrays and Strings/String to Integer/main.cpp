/*
 * main.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

int stringToInteger(string input){
	int result = 0;
	for(int i = 0; i < input.length(); ++i)
		result = 10*result + (input.at(i) - '0');
	return result;
}

string integerToString(int input){
	string result = "";
	int temp = input;
	while(temp!=0){
		result = (char)(temp%10 + '0') + result;
		temp/=10;
	}
	return result;
}

int main(){
	string s = "33467";
	cout<<stringToInteger(s)<<endl;


	cout<<integerToString(1103);
	 return 0;
}



