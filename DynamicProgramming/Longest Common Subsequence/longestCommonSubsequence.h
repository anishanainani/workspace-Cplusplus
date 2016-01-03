/*
 * longestCommonSubsequence.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Komani
 */

#ifndef LONGESTCOMMONSUBSEQUENCE_H_
#define LONGESTCOMMONSUBSEQUENCE_H_

#include<iostream>
#include<vector>

using namespace std;

class longestCommonSubsequence{
	private:
		vector< vector<int> > matrix, keep;
		string x;
		string y;
		enum{MATCH, INSERT, DELETE};

	public:
		longestCommonSubsequence(string xin, string yin) : x(xin), y(yin){};
		void findLCS();
		void printLCS(int, int);
};

void longestCommonSubsequence :: findLCS(){

	vector<int> rows;
	//Initializing matrix
	rows.assign(y.length()+1, 0); // assigning a rows with zeros
	matrix.assign(x.length()+1,rows);	//assigning rows to the matrix
	keep.assign(x.length()+1, rows);

	for(unsigned i = 1; i <= x.length(); ++i){
			for(unsigned j = 1; j <= y.length(); ++j){
				if(x.at(i-1) == y.at(j-1)){
					matrix[i][j] = matrix[i-1][j-1] + 1;
					keep[i][j] = MATCH;
				} else {
					if(matrix[i][j-1] < matrix[i-1][j]){
						matrix[i][j] = matrix[i-1][j];
						keep[i][j] = INSERT;
					} else {
						matrix[i][j] = matrix[i][j-1];
						keep[i][j] = DELETE;
					}
				}
			}
		}

		printLCS(x.length(), y.length());
}

void longestCommonSubsequence :: printLCS(int i, int j){
	if(i==0 || j==0) return;

	if(keep[i][j] == MATCH){
		printLCS(i-1, j-1);
		cout<<x[i-1];
	} else if(keep[i][j] == INSERT){
		printLCS(i-1, j);
	} else if(keep[i][j] == DELETE){
		printLCS(i, j-1);
	}
};

#endif /* LONGESTCOMMONSUBSEQUENCE_H_ */
