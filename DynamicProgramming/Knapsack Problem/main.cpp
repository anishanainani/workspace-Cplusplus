/*
 * main.cpp
 *
 *  Created on: Feb 7, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>

using namespace std;

void Knapsack(vector<int>& weights, vector<int>& values, int knapsackWeight){

		vector< vector<int> > matrix, keep;	//matrices with items as rows and weights as columns
		vector<int> weightsInKnapsack;	//rows of matrix
		int numberOfItems = weights.size();

		//Initializing matrix
		weightsInKnapsack.assign(knapsackWeight+1, 0); // assigning a rows with zeros
		matrix.assign(numberOfItems+1, weightsInKnapsack);	//assigning rows to the matrix
		keep.assign(numberOfItems+1, weightsInKnapsack);

		for(int i = 1; i <= numberOfItems; ++i){
			for(int j = 1; j <= knapsackWeight; ++j){
				int temp;
				if((j-weights[i]) < 0) {
					temp = 0;
				} else {
					temp = matrix[i-1][j-weights[i]] + values[i];
				}

				if(temp>matrix[i-1][j]){
					matrix[i][j] = temp;
					keep[i][j] = 1;
				} else {
					matrix[i][j] =  matrix[i-1][j];
					keep[i][j] = 0;
				}
			}
		}

		if(matrix[numberOfItems][knapsackWeight] != knapsackWeight){
				cout<<"No result found."<<endl;
		} else {
				cout<<"Total Value "<<matrix[numberOfItems][knapsackWeight]<<endl;

				cout<<"Items used : "<<endl;
				//Tracking the items used from keep matrix
				int weight = knapsackWeight;
				for(int item = numberOfItems; item > 0; --item){
					if(keep[item][weight] == 1){
						weight-=weights[item];
						cout<<"Item "<<item<<" Value "<<values[item]<<endl;
					}
				}
		}

}

void subsetSum(vector<int>& input, int container){
	Knapsack(input, input, container);
};

int main(){

	/*
	int w[] = {0,3,2,1};
	vector<int> weights(w, w+4);

	int v[] = {0,5,3,4};
	vector<int> values(v, v+4);

	int knapsackWeight = 5;
	Knapsack(weights, values, knapsackWeight);
	*/

	int numbers[] = {0,2,4,7,9}; //element at index 0 not used
	int length = sizeof(numbers)/sizeof(numbers[0]);
	vector<int> inputArray(numbers, numbers+length);
	subsetSum(inputArray, 15);
	return 0;
}


