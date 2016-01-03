/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

void reverseString(char* input){
	if(input){
		char * end;
		for(end = input; *end!= '\0'; ++end);
		--end;

		while(input < end){
			char temp = *input;
			*input++ = *end;
			*end-- = temp;

		}
	}
};

int main(){

	char* input = "abcd";
	reverseString(input);

	cout<<input;

	return 0;
}


