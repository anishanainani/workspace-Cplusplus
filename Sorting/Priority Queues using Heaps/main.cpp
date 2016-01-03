/*
 * main.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: Komani
 *
 */

#include<iostream>
#include "priority_queue.h"

using namespace std;

int main(){

	priority_queue<int> pq;
	pq.max_heap_insert(5);
	pq.max_heap_insert(4);
	pq.max_heap_insert(1);
	pq.max_heap_insert(3);

	cout<<pq.heap_extract_max()<<endl;
	pq.heap_increase_key(3, 8);

	cout<<pq.heap_extract_max();
	return 0;
}
