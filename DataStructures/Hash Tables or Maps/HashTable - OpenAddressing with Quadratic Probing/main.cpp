/*
 * main.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: Komani
 */

#include<iostream>
#include "HashTable.h"
#include "EmployeeTelephoneRecords.h"

using namespace std;

int main(){


	HashTable<EmployeeTelephoneRecords, string, long long int> h;

	h.insert("Anisha", 8587332276);
	h.insert("Komal", 7898280810);
	h.insert("Vishi", 8976543221);
	h.insert("Tarun", 2134589089);
	h.insert("Ritika", 2134585609);

	if(h.searchValue("Komal"))
		cout<<"Komal's Phone number is : "<<h["Komal"]<<endl;

	h.remove("Vishi");


	return 0;
}



