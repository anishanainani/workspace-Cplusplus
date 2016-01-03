/*
 * main.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Komani
 *
 *      heap_sort.h :
 *      	constructor : heap_sort(item_type* array, int length_of_array)
 *      	sorting function : void sort()
 */

#include<iostream>
#include "heap_sort.h"

using namespace std;

int main(){
	int * numbers = new int[6];
	for(int i = 1; i <= 5; i++){
		cin>>numbers[i];
	}
	heap_sort<int> h(numbers, 5);
	h.sort();
	for(int i = 1; i<=5; i++) cout<<numbers[i]<<endl;
	return 0;
}
