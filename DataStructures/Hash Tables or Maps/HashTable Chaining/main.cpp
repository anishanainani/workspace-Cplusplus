/*
 * main.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: Komani
 */

#include<iostream>
#include "HashTable.cpp"
#include "EmployeeTelephoneRecords.cpp"

using namespace std;


int main(){

	EmployeeTelephoneRecords e1("Anisha", 8587332276), e2("Komal", 89803267);

	HashTable<EmployeeTelephoneRecords, string> h;
	if(h.contains(e1)) cout<<"gg";
	h.insert(e1);
	//h.insert(e2);

	//cout<<h.searchValue("Anisha");

	return 0;
}
