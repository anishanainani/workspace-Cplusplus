/*
 * heap_sort.h
 *
 *  Created on: Jan 27, 2015
 *      Author: Komani
 */

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include<iostream>

using namespace std;

template<typename item_type>
class heap_sort{
	public:
		heap_sort() : array(NULL), length(0), heap_size(0){};
		heap_sort(item_type* a, int len) : array(a), heap_size(len), length(len){};

		int parent(int i){ return (int)(i>>1);};
		int left(int i){ return i<<1;};
		int right(int i){ return ((i<<1)+1);};

		void max_heapify(int);
		void build_maxheap();
		void sort();
		void swap(int, int);

	private:

		item_type* array;
		int heap_size;
		int length;
};

//O(logn)
template<typename item_type>
void heap_sort<item_type> :: max_heapify(int i){	//O(logn)
	int left_child = left(i);
	int right_child = right(i);
	int largest;

	if(left_child <= heap_size && array[left_child] > array[i]){
		largest = left_child;
	} else largest = i;

	if(right_child <= heap_size && array[right_child] > array[largest]){
			largest = right_child;
	}

	if(largest != i){
		swap(i, largest);
		max_heapify(largest);
	}

}


template<typename item_type>
void heap_sort<item_type> :: build_maxheap(){	//O(n)
	for(int i = (length/2); i>=1; i--){
		max_heapify(i);
	}
}

template<typename item_type>
void heap_sort<item_type> :: sort(){	//O(nlogn)
	build_maxheap();
	for(int i = length; i>=2; i--){
		swap(1, i);
		--heap_size;
		max_heapify(1);
	}

}

template<typename item_type>
void heap_sort<item_type> :: swap(int index1, int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}


#endif /* HEAP_SORT_H_ */
