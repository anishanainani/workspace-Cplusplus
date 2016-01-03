/*
 * Combinations.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#ifndef COMBINATIONS_H_
#define COMBINATIONS_H_

#include<iostream>

using namespace std;

class Combinations{
	public:
		Combinations(string in) : input(in), out("") {}
		void combine();
		void combine(int);
	private:
		const string input;
		string out;
};

void Combinations :: combine(){
	combine(0);
};


void Combinations :: combine(int start){

	for(int i = start; i < input.length(); ++i){
		out+=input.at(i);
		cout<<out<<endl;
		if(i < input.length()) combine(i+1);

		out.resize(out.length()-1);
	}
};



#endif /* COMBINATIONS_H_ */
