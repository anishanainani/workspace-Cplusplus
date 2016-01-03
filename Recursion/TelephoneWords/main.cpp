/*
 * main.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */
#include<iostream>
#include "TelephoneWords.h"

using namespace std;

int main(){
	int* numbers = new int[7];
	for(int i = 0; i < 7; ++i){
		cin>>numbers[i];
	}
	TelephoneWords t(numbers);
	t.telephoneWords(0);
	return 0;
}



