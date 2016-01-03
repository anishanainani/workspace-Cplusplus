/*
 * main.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

int a[] = {1, 3, 7, 9, 10, 0, 0, 0};
int b[] = {2, 4, 8};

void mergeArrays(int m, int n){
	int k = m+n-1;
	int i = m-1;
	int j = n-1;

	while(i>=0 && j >=0){
		if(a[i] > b[j]){
			a[k--] = a[i--];
		} else {
			a[k--] = b[j--];
		}
	}

	while(j>=0){
		a[k--] = b[j--];
	}
};

int main(){
	mergeArrays(5, 3);

	for(int i = 0; i < 8; ++i) cout<<a[i]<<endl;
	return 0;
}


