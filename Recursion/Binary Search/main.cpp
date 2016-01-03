/*
 * main.cpp
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

bool BSearch(int* sortedArray, int start, int end, int value){
	if(start > end) {
		cout<<"Limits Reversed"<<endl;
		return false;;
	}
	else if(start == end && sortedArray[start] != value) {
		cout<<"Element not found"<<endl;
		return false;
	}

	if(sortedArray[start] > sortedArray[end]){
		cout<<"Array not sorted"<<endl;
		return false;
	}

	int mid = (end-start)/2+start;

	if(sortedArray[mid] == value) return true;
	else if(sortedArray[mid] > value) return BSearch(sortedArray, start, mid-1,value);
	else return BSearch(sortedArray, mid+1,end, value);
}

int main(){
	int* numbers = new int[6];
	for(int i = 0; i < 6; ++i){
		cin>>numbers[i];
	}
	int searchNum;
	cout<<"Enter element to be searched : "<<endl;
	cin>>searchNum;
	if(BSearch(numbers, 0, 4, searchNum)) cout<<"Number found"<<endl;

	return 0;
}


