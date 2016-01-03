/*
 * merge_sort.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *  Can be optimized by using insertion sort for sorting small sized subproblems
 *
 *  Its a good choice for sorting large data sets that are too large to fit in memory, in which large files are split into multiple smaller ones
 *  each of which is read into memory, sorted and written back out
 *
 *  Best, worst and average case running times are O(nlogn)
 *  thats why its used where guaranteed O(nlogn) complexity is needed
 *
 *  O(n) space complexity
 *
 *  Not inplace
 *  Stable
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include<iostream>

using namespace std;

template<typename item_type>
class merge_sort{
	public:
		merge_sort() : array(NULL), length(0) {};
		merge_sort(item_type* a, int l) : array(a), length(l){};
		void sort(int, int);
		void merge(int, int, int);
	private:
		item_type* array;
		int length;
};

template<typename item_type>
void merge_sort<item_type> :: sort(int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		sort(start, mid);
		sort(mid+1, end);
		merge(start, mid, end);
	}
};

template<typename item_type>
void merge_sort<item_type> :: merge(int start, int mid, int end){

	int left_length = mid - start + 1;
	int right_length = end - mid;
	item_type left[left_length];
	item_type right[right_length];

	for(int i = 0; i < left_length; i++){
		left[i] = array[start + i];
	}

	for(int i = 0; i < right_length; i++){
		right[i] = array[mid + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k;

	for(k = start; i<left_length && j<right_length; ++k){
		if(left[i] < right[j]){
			array[k] = left[i];
			++i;
		} else {
			array[k] = right[j];
			++j;
		}
	}

	while(i<left_length){
		array[k++] = left[i++];
	}

	while(j<right_length){
		array[k++] = right[j++];
	}
};

#endif /* SELECTION_SORT_H_ */
