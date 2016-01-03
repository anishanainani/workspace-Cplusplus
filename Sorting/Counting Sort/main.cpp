/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: Komani
 *
 *  When input's maximum element is O(n), then it runs in O(n) time.
 *
 *  Counting sort determines, for each input element x, the number of elements less
 *  than x. It uses this information to place element x directly into its position in the
 *  output array
 *
 *  O(n+k), thus linear when k = O(n)
 *
 *  Stable
 */

#include<iostream>

using namespace std;

void counting_sort(int* array, int* sorted_array, const int length, const int largest){
	int* count = new int[largest+1];

	for(int i = 0; i <= largest; i++){	//O(k)
		count[i] = 0;
	}

	for(int i = 0; i < length; i++){	//O(n)
		++count[array[i]];
	}

	for(int i = 1; i <=largest; i++){	//O(k)
		count[i]+=count[i-1];
	}

	for(int i = length-1; i >=0; --i){	//O(n)
		sorted_array[count[array[i]]] = array[i];
		--count[array[i]];
	}


};

int main(){
	int* array = new int[7];
	int* sorted_array = new int[7];
	for(int i = 0; i < 6; i++){
			cin>>array[i];
	}
	counting_sort(array,sorted_array, 6, 7);

	cout<<"Sorted array : "<<endl;
	for(int i = 0; i < 6; i++){
		cout<<sorted_array[i]<<endl;
	}
	return 0;
}


