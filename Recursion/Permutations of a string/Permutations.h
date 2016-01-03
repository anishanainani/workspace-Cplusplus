/*
 * Permutations.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include<iostream>

using namespace std;

class Permutations{
	public:
		Permutations(const string in) : input(in) , out(""){
			used = new bool[input.length()];
			for(int i = 0; i < input.length(); ++i) used[i] = false;
		};

		void permute();

	private:
		string input;
		string out;
		bool* used;
};

void Permutations :: permute(){
	if(input.length() == out.length()){
		cout<<out<<endl;
		return;
	}

	for(int i = 0; i < input.length(); ++i){

		if(used[i]) continue;
		out +=input.at(i);
		used[i] = true;
		permute();
		used[i] = false;
		out.resize(out.length() - 1);
	}
}

#endif /* PERMUTATIONS_H_ */
