/*
 * main.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *  qick_sort.h : quick_sort(item_type* array, int length_of_array);
 *   				    sort(int start_index, int end_index);
 *
 */


#include<iostream>
#include "quick_sort.h"

using namespace std;

int main(){
	int * numbers = new int[5];

	for(int i = 0; i < 5; i++) cin>>numbers[i];
	quick_sort<int> q(numbers, 5);
	q.sort(0, 4);
	cout<<"Sorted array: "<<endl;
	for(int i = 0; i < 5; i++) cout<<numbers[i]<<endl;
	return 0;
}
