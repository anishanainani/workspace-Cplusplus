/*
 * main.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *   insertion_sort.h : insertion_sort(item_type* array, int length_of_array);
 *   				    sort();
 *
 */


#include<iostream>
#include "insertion_sort.h"

using namespace std;

int main(){
	int * numbers = new int[5];

	//Simple Selection sort
	for(int i = 0; i < 5; i++) cin>>numbers[i];
	insertion_sort<int> i;
	i.sort(numbers, 5);
	cout<<"Sorted array: "<<endl;
	for(int i = 0; i < 5; i++) cout<<numbers[i]<<endl;


	return 0;
}
