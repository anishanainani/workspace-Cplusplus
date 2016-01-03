/*
 * main.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *   selection_sort.h : selection_sort(item_type* array, int length_of_array);
 *   				    sort();
 *
 *   selection_sort_recursive.h : selection_sort_recursive(item_type* array, int length_of_array);
 *   							  sort(int start_index);
 */


#include<iostream>
#include "selection_sort.h"
#include "selection_sort_recursive.h"

using namespace std;

int main(){
	int * numbers = new int[5];

	//Simple Selection sort
	for(int i = 0; i < 5; i++) cin>>numbers[i];
	selection_sort<int> s(numbers, 5);
	s.sort();
	cout<<"Sorted array: "<<endl;
	for(int i = 0; i < 5; i++) cout<<numbers[i]<<endl;

	//Recursive Selection sort
	for(int i = 0; i < 5; i++) cin>>numbers[i];
	selection_sort_recursive<int> sr(numbers, 5);
	sr.sort(0);
	cout<<"Sorted array: "<<endl;
	for(int i = 0; i < 5; i++) cout<<numbers[i]<<endl;

	return 0;
}
