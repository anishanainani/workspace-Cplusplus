/*
 * main.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: Komani
 */

#include<iostream>
#include "StringCompare.h"
#include "SubstringMatching.h"
using namespace std;

int main(){
	string sr("skiena"), t("skienskinaskiena");

	//StringCompare s(sr, t);
	//cout<<s.string_compare()<<endl;

	SubstringMatching s(sr, t);
	cout<<s.substring_match()<<endl;

	s.reconstruct_path();
	return 0;
}


