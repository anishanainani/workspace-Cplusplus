/*
 * main.cpp
 *
 *  Created on: Feb 11, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>

using namespace std;

//O(nm)
void zeroRowColumn(vector< vector<int> > & matrix){
	int * rows = new int[matrix.size()];
	int * columns = new int[matrix[0].size()];

	for(int i = 0; i < matrix.size(); ++i){
		for(int j = 0; matrix[0].size(); ++j){
			if(matrix[i][j] == 0) {
				rows[i] = 1;
				columns[j] = 1;
			}
		}
	}

	for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; matrix[0].size(); ++j){
				if(rows[i] == 1 || columns[j] == 1) {
					matrix[i][j] = 0;
				}
			}
	}
}


