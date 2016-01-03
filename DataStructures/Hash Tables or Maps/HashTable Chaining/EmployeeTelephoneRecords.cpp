/*
 * EmployeeTelephoneRecords.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: Komani
 */
#ifndef EMPLOYEETELEPHONERECORDS_CPP
#define EMPLOYEETELEPHONERECORDS_CPP

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "HashTable.cpp"

using namespace std;

class EmployeeTelephoneRecords{

	public:
		EmployeeTelephoneRecords(string k, int v) : key(k), value(v){};
		string getKey() { return key; }
		int getValue() { return value; }
		void setKey(const string & k) { key = k; }
		void setValue(const int & v) { value = v; }
		bool operator==(EmployeeTelephoneRecords e){ return getKey() == e.getKey(); }
		bool operator!=(EmployeeTelephoneRecords e){ return getKey() != e.getKey(); }


	private:
		string key;
		int value;

};

#endif
