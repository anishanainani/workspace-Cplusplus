/*
 * main.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Komani
 */

#include<iostream>
#include<list>

using namespace std;

void sum(list<int>& num1, list<int>& num2, list<int>& result){
	typename list<int> :: iterator itr1 = num1.begin();
	typename list<int> :: iterator itr2 = num2.begin();
	int carry = 0, sum = 0;

	while(itr1!= num1.end() && itr2!=num2.end()){
		sum = *itr1 + *itr2;
		result.push_back(sum%10 + carry);
		if(sum>9) carry = 1;
		else carry = 0;
		++itr1; ++itr2;
	}


	while(itr1!=num1.end()){
		sum = *itr1+ carry;
		result.push_back(sum%10 + carry);
		if(sum > 9) carry = 1;
		else carry = 0;
		++itr1;
	}

	while(itr2!=num2.end()){
		sum = *itr2 + carry;
		result.push_back(sum%10 + carry);
		if(sum > 9) carry = 1;
		else carry = 0;
		++itr2;
	}

	if(carry == 1) result.push_back(carry);


};

int main(){
	list<int> num1, num2, result;
	num1.push_back(3);
	num1.push_back(1);
	num1.push_back(5);
	num1.push_back(9);

	num2.push_back(5);
	num2.push_back(9);
	num2.push_back(5);

	sum(num1, num2, result);

	for(list<int> :: iterator it = result.begin(); it!=result.end(); ++it){
		cout<<*it<<endl;
	}
	return 0;
}

