/*
 * selection_sort.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *  Best case: already sorted - O(n)
 *  Avg and worst - O(n^2)
 *  Stable
 *  inplace
 *
 *  Best algorithm for small data sets
 */

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_

#include<iostream>

using namespace std;

template<typename item_type>
class insertion_sort{
	public:
		insertion_sort() : array(NULL), length(0) {};
		void sort(item_type*, int);
		void swap(int, int);
	private:
		item_type* array;
		int length;
};

template<typename item_type>
void insertion_sort<item_type> :: sort(item_type* a, int l){
	array = a;
	length = l;
	for(int which = 1; which < length; which++){
		int i;
		int value = array[which];

		for(i = which-1;i >= 0 && (array[i] > value) ; --i){
				//shifting the elements of the array to which
				array[i+1] = array[i];


		}
		array[i+1] = value;
	}
};



#endif /* INSERTION_SORT_H_ */
