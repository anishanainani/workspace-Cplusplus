/*
 * selection_sort_recursive.h
 *
 *  Created on: Jan 28, 2015
 *      Author: Komani
 */

#ifndef SELECTION_SORT_RECURSIVE_H_
#define SELECTION_SORT_RECURSIVE_H_

#include<iostream>

using namespace std;

template<typename item_type>
class selection_sort_recursive{
	public:
		selection_sort_recursive() : array(NULL), length(0) {};
		selection_sort_recursive(item_type* a, int l) : array(a), length(l){};
		void sort(int);
		void swap(int, int);
		int findMinimumIndex(int);
	private:
		item_type* array;
		int length;
};

template<typename item_type>
void selection_sort_recursive<item_type> :: sort(int start){
	if(start < length-1){
		swap(start, findMinimumIndex(start));
		sort(start+1);
	}
};

template<typename item_type>
void selection_sort_recursive<item_type> :: swap(int index1, int index2){
	item_type temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

template<typename item_type>
int selection_sort_recursive<item_type> :: findMinimumIndex(int start){
	int minPos = start;
	for(int i = start+1; i < length; i++){
		if(array[i] < array[minPos]){
			minPos = i;
		}
	}

	return minPos;
}




#endif /* SELECTION_SORT_RECURSIVE_H_ */
