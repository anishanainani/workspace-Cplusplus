/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */

/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */


#include<iostream>
#include<vector>

using namespace std;

void printParanthesis(string left, string right){
	if(left.size() == 0) return;

	string temp_left = left, temp_right = right;

	if(left.size()>2){
		for(unsigned i = 1; i < left.length()/2; i+=2){

				temp_left.at(i) = '(';
				temp_left.at(left.size()-i-1) = ')';
				cout<<temp_left<<right<<endl;
		}
	}


	if(right.size()>2){
		for(unsigned i = 1; i < right.size()/2; i+=2){

				temp_right.at(i) = '(';
				temp_right.at(right.size()-i-1) = ')';
				cout<<left<<temp_right<<endl;

		}
	}

	printParanthesis(left.substr(0, left.size()-2), right+left.substr(left.size()-2));

};

int main(){

	//int n = 4;
	string in("()()()()()");
	printParanthesis(in, "");
	return 0;
}






