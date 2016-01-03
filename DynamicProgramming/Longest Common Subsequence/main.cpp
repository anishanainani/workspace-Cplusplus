/*
 * main.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>
#include "longestCommonSubsequence.h"

using namespace std;

int main(){
	longestCommonSubsequence lcs("abcdefgh", "avhibcdoole");
	cout<<"Longest subsequence is : ";
	lcs.findLCS();
	return 0;
}


