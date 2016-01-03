/*
 * main.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: Komani
 */
#include<iostream>

using namespace std;

int matrix[3][4] = {
			{1,2,3,4},
			{5,6,7,8},
			{9, 10, 11, 12}
	};

void find(int elem, int &ri, int &rj){
	int i = 2, j= 0;
	while(i>=0 && j <4){
		if(elem==matrix[i][j]){
			ri = i; rj = j;
			break;
		} else if(elem > matrix[i][j]){
			++j;
		} else {
			--i;
		}
	}


}

int main(){


	int num =100;
	int resulti = -1, resultj = -1;

	find(num,resulti, resultj);
	cout<<resulti<<" "<<resultj;

	return 0;
}


