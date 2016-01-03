/*
 * main.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>

using namespace std;

void rotateMatrix(vector<vector<char> >& matrix) {
	int length = matrix.size();
	for(int level = 0; level < length/2; ++level){
		int first = level;
		int last = length - 1 - level;
		for(int i = level; i < length-level; ++i){

			int temp = matrix[last-i][first];

			matrix[last-i][first] = matrix[last][last-i];

			matrix[last][last-i] = matrix[i][last];

			matrix[i][last] = matrix[first][i];

			 matrix[first][i] = temp;
		}
	}
};

int main(){

	vector<vector<char> > matrix;

	vector<char> rows;
	for(int i = 0; i < 5; ++i){
		if(i == 2) rows.push_back('a');
		rows.push_back('*');
	}

	matrix.assign(5, rows);

	for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
					cout<<matrix[i][j]<<" ";
			}

			cout<<endl;
	}

	rotateMatrix(matrix);

	cout<<"After Rotating"<<endl;

	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
				cout<<matrix[i][j]<<" ";
		}

		cout<<endl;
	}


	return 0;
}


