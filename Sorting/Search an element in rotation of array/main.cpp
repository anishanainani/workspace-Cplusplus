/*
 * main.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

int find(int* array, int start, int end, int elem){

	while(start<=end){
		int mid = (start+end)/2;
		if(array[mid] == elem){
			return mid;
		} else if(array[start]<=array[mid]){
			if(elem > array[mid]){
				start = mid+1;
			} else if(elem <= array[start]){
				end = mid-1;
			} else {
				start = mid+1;
			}
		} else if(elem < array[mid]) end = mid-1;
		else if(elem <=array[end]) start = mid+1;
		else end = mid-1;
	}

	return -1;

};

int main(){

	int array[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
	cout<<find(array, 0, 11, 5);

	return 0;
}


