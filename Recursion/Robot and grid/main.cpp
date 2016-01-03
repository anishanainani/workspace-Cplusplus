/*
 * main.cpp
 *
 *  Created on: Feb 15, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>

using namespace std;


int count = 0;
vector<string> path;

bool robot(int n, int i, int j){

	if(i==n-1 && j==n-1){
		for(unsigned k = 0; k<path.size(); ++k){
			cout<<path[k]<<"  ";
		}
		cout<<endl;
		path.clear();
		++count;
		return true;
	}

	bool success = false;

	//if(i==n-1 || j==n-1) return false;


	path.push_back("right");
	if(j<n)
	success = robot(n, i, j+1);

	if(!success && i<n){
		path.push_back("down");
		success = robot(n, i+1, j);
	}
	if(!success) path.clear();

		return success;
};

int main(){

	robot(3, 0, 0);
	cout<<count;
	return 0;
}


