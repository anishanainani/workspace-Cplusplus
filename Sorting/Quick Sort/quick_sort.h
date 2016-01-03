/*
 * quick_sort.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 *
 *  Performance depends upon the choice of the pivot element
 *  The ideal pivot element is that which splits the array into 2 equal subproblems O(nlogn)
 *  Worst case pivot choice is smallest or largest element in which case it becomes O(n^2)
 *  If data is already sorted it is better to take middle element as pivot
 *  Unstable
 *  Inplace
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;

template<typename item_type>
class quick_sort{
	public:
		quick_sort() : array(NULL), length(0) {};
		quick_sort(item_type* a, int l) : array(a), length(l){};
		void sort(int, int);
		void swap(int, int);
		int randomized_partition(int, int);
		int partition(int, int);
	private:
		item_type* array;
		int length;
};

template<typename item_type>
void quick_sort<item_type> :: sort(int start, int end){
	if(start<end){
		int pivot = randomized_partition(start, end);
		sort(start, pivot-1);
		sort(pivot+1, end);
	}
};

template<typename item_type>
int quick_sort<item_type> :: randomized_partition(int start, int end){
	srand((unsigned)time(0));
	int random_number = start + (rand()%(end-start))+1;
	swap(random_number, end);

	return partition(start, end);
}

template<typename item_type>
int quick_sort<item_type> :: partition(int start, int end){
	int pivot = array[end];
	int j = start-1;

	for(int i = start; i < end; i++){
		if(array[i] < pivot){
			++j;
			swap(i, j);
		}
	}

	swap(++j, end);
	return j;
}

template<typename item_type>
void quick_sort<item_type> :: swap(int index1, int index2){
	item_type temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}


#endif /* SELECTION_SORT_H_ */
