/*
 * main.cpp
 *
 *  Created on: Feb 3, 2015
 *      Author: Komani
 */

#include<iostream>

using namespace std;

void bCoefficients(int n, int k){
	int bcMatrix[n+1][n+1];

	for(int i = 0; i <= n; ++i){
		bcMatrix[i][0] = 1;
	}

	for(int i = 0; i <= n; ++i){
			bcMatrix[i][i] = 1;
	}

	for(int i = 1; i <=n; i++){
		for(int j = 1; j < i; ++j){
			bcMatrix[i][j] = bcMatrix[i-1][j-1] + bcMatrix[i-1][j];

		}
	}

	cout<<bcMatrix[n][k];
}

int main(){
	bCoefficients(6, 4);
	return 0;
}


