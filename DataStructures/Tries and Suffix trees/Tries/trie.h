/*
 * trie.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Anisha
 */

#ifndef TRIE_H_
#define TRIE_H_

#include<iostream>
#include<vector>
#include "node.h"

using namespace std;

class trie{
	private:
		node* root;
	public:
		trie() : root(NULL){};

		void addWord(string);
		void addWordWrapper(node*,string);

		node* getRoot(){ return root; }

		int countWords(string&);
		int countPrefixes(string&);

		node* getPrefixEdge(vector<node*>&, char);

		void display(vector<node*>&);

		int countMatchingWords(string);
		int countMatchingWordsWrapper(node*,string);

		int countMatchingPrefixes(string);
		int countMatchingPrefixesWrapper(node*,string);
};

#endif /* TRIE_H_ */
