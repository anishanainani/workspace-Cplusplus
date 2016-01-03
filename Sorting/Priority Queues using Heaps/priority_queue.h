/*
 * heap_sort.h
 *
 *  Created on: Jan 27, 2015
 *      Author: Komani
 */

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_

#include<iostream>
#include<vector>

using namespace std;

template<typename item_type>
class priority_queue{
	public:
		priority_queue() : heap_size(0){array.push_back(0);};

		int parent(int i){ return (int)(i/2);};
		int left(int i){ return 2*i;};
		int right(int i){ return (2*i+1);};

		void max_heapify(int);
		void build_maxheap();
		void swap(int, int);

		item_type heap_maximum(){ if(heap_size > 1) return array[1]; return NULL;};
		item_type heap_extract_max();
		void heap_increase_key(int, item_type);
		void max_heap_insert(item_type);
	private:

		vector<item_type> array;
		int heap_size;
};


template<typename item_type>
void priority_queue<item_type> :: max_heapify(int i){
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
void priority_queue<item_type> :: build_maxheap(){
	for(int i = (array.size()/2); i>=1; i--){
		max_heapify(i);
	}
}

template<typename item_type>
item_type priority_queue<item_type> :: heap_extract_max(){
	if(array.size() < 1){
		cout<<"Heap underflow."<<endl;
		return (item_type)0;
	}

	item_type max = array[1];
	array[1] = array[heap_size];
	--heap_size;
	max_heapify(1);

	return max;
}

template<typename item_type>
void priority_queue<item_type> :: heap_increase_key(int i, item_type key){
	if(key < array[i]){
		cout<<"New key is smaller than the old one."<<endl;
	}

	array[i] = key;
	while(i>1 && array[parent(i)] < array[i]){
		swap(parent(i), i);
		i = parent(i);
	}

	cout<<"Key Increase Successful."<<endl;
}

template<typename item_type>
void priority_queue<item_type> :: max_heap_insert(item_type key){
	heap_size+=1;
	array.push_back(-1);
	heap_increase_key(heap_size, key);
}

template<typename item_type>
void priority_queue<item_type> :: swap(int index1, int index2){
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}


#endif /* HEAP_SORT_H_ */
