/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */


#include<iostream>
#include<vector>

using namespace std;

void printCombinations(vector<int>& input){
	int size = input.size();
	vector< vector<int> > subsets;

	int max = 1<<size;

	int k = 0;

	for(int i = 0; i < max; ++i){
		vector<int> subset;
		int index = 0;
		k=i;
		while(k>0){
			if((k&1) > 0){
				subset.push_back(input[index]);
			}

			++index;
			k>>=1;
		}
		subsets.push_back(subset);
	}

	for(unsigned i = 0; i < subsets.size(); ++i){
		for(unsigned j = 0; j < subsets[i].size(); ++j){
			cout<<subsets[i][j]<<" ";
		}

		cout<<endl;
	}

};

int main(){
	int arr[] = {1,2,3, 4};
	vector<int> input(arr, arr+4);
	printCombinations(input);
	return 0;
}



