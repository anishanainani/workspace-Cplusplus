/*
 * selection_sort.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *   n-1 + n-2 + n-3 + ..... = O(n^2)
 *
 *   Advantage:
 *   atmost n-1 swaps, the situations in which moving data elements is more expensive than comparing, selection sort is good.
 *
 *	Not stable
 *	inplace
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include<iostream>

using namespace std;

template<typename item_type>
class selection_sort{
	public:
		selection_sort() : array(NULL), length(0) {};
		selection_sort(item_type* a, int l) : array(a), length(l){};
		void sort();
		void swap(int, int);
	private:
		item_type* array;
		int length;
};

template<typename item_type>
void selection_sort<item_type> :: sort(){
	cout<<sizeof(array);
	for(int i = 0; i < length-1; ++i){
		int min_index = i;
		for(int j = i+1; j < length; ++j){
			if(array[j] < array[min_index]){
				min_index = j;
			}
		}

		swap(i, min_index);
	}
};

template<typename item_type>
void selection_sort<item_type> :: swap(int index1, int index2){
	item_type temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}



#endif /* SELECTION_SORT_H_ */
