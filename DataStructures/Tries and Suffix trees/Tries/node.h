/*
 * node.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Anisha
 */

#ifndef NODE_H_
#define NODE_H_

#include<iostream>
#include<vector>

using namespace std;

class node{
	private:
		char letter;
		vector<node*> edges;
		int words ;
		int prefixes;

	public:
		node(char l) : letter(l),words(0), prefixes(0){};
		char getLetter(){ return letter; }
		int getWordCount(){ return words; }
		vector<node*> & getEdges(){ return edges;}
		int getPrefixCount(){ return prefixes;}

		void setWordCount(int w){ words = w; }
		void setPrefixCount(int p){prefixes = p; }
		void setLetter(char let) { letter = let; }

};


#endif /* NODE_H_ */
