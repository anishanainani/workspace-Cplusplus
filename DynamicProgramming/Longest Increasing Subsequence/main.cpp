/*
 * main.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Anisha
 */

#include<iostream>
#include<vector>

using namespace std;

int main(){
	int input[] = {3,2,6,4,5,1,8,9,0};

	unsigned size = sizeof(input)/sizeof(input[0]);

	vector< vector<int> > L;
	vector<int> v;
	L.assign(size, v);
	int maxi = 0;
	for(unsigned i = 0; i < size; ++i){
		for(unsigned j = 0; j < i; ++j){
			if(input[i] > input[j] && (L[i].size() < L[j].size() + 1)){
				L[i] = L[j];
				maxi = i;
			}
		}

		L[i].push_back(input[i]);

	}

	//cout<<"Longest increasing subsequence : ";
	for(unsigned i = 0; i < L.size(); ++i){
		for(unsigned j = 0; j < L[i].size(); ++j){
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}


