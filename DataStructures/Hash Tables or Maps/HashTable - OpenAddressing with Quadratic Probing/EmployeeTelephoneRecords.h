/*
 * EmployeeTelephoneRecords.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Komani
 */

#ifndef EMPLOYEETELEPHONERECORDS_H_
#define EMPLOYEETELEPHONERECORDS_H_

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class EmployeeTelephoneRecords{
	public:

		EmployeeTelephoneRecords() {}
		EmployeeTelephoneRecords(string name,long long int number) : emp_name(name), phoneNumber(number){};

		string getKey() { return emp_name; };
		long long int getValue() { return phoneNumber; };
		void setKey (string key) { emp_name = key; };
		void setValue(long long int value) { phoneNumber = value; };
		bool operator==( EmployeeTelephoneRecords & x) {return getKey() == x.getKey(); };
		bool operator!=(EmployeeTelephoneRecords & x) {return getKey() != x.getKey(); };

	private:
		string emp_name;
		long long int phoneNumber;

};


#endif /* EMPLOYEETELEPHONERECORDS_H_ */
