/*
 * trie.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Anisha
 */

#include<iostream>
#include<vector>
#include "node.h"
#include "trie.h"

using namespace std;

void trie:: addWord(string word){
	if(!root){
		root = new node('\0');
	}
	addWordWrapper(root, word);
}

void trie:: addWordWrapper(node* vertex, string word){

	if(word.empty()){
		vertex->setWordCount(vertex->getWordCount()+1);
	} else {
		vertex->setPrefixCount(vertex->getPrefixCount()+1);
		char firstChar = word.at(0);
		node* prefixEdge = getPrefixEdge(vertex->getEdges(), firstChar);

		if(!prefixEdge){
			node* newNode = new node(firstChar);
			if(!newNode){
				cout<<"Memory Allocation Failed"<<endl;
				return;
			}
			vertex->getEdges().push_back(newNode);
			prefixEdge = newNode;
		}

		if(word.size()==1){
			addWordWrapper(prefixEdge, "");
		} else {
			addWordWrapper(prefixEdge, word.substr(1, word.length()-1));
		}
	}
}

node* trie:: getPrefixEdge(vector<node*>& edges, char ch){
	for(unsigned i = 0; i < edges.size(); ++i){
		if(edges[i]->getLetter() == ch){
			return edges[i];
		}
	}
	return NULL;
}

void trie:: display(vector<node*> &edges){
		for(unsigned i = 0; i < edges.size(); ++i){
			cout<<edges[i]->getLetter()<<endl;
			display(edges[i]->getEdges());
		}
}

int trie :: countMatchingWords(string word){
	return countMatchingWordsWrapper(root, word);
}

int trie :: countMatchingWordsWrapper(node* vertex, string word){
	if(word.empty()){
		return vertex->getWordCount();
	}

	char firstChar = word.at(0);
	node* prefixEdge = getPrefixEdge(vertex->getEdges(), firstChar);

	if(prefixEdge){

		if(word.size()==1){
			return countMatchingWordsWrapper(prefixEdge, "");
		} else {
			return countMatchingWordsWrapper(prefixEdge, word.substr(1, word.length()-1));
		}
	}

	return 0;
}

int trie :: countMatchingPrefixes(string word){
	return countMatchingPrefixesWrapper(root, word);
}

int trie :: countMatchingPrefixesWrapper(node* vertex, string prefix){
	if(prefix.empty()){
		return vertex->getPrefixCount();
	}

	char firstChar = prefix.at(0);
	node* prefixEdge = getPrefixEdge(vertex->getEdges(), firstChar);

	if(prefixEdge){

		if(prefix.size()==1){
			return countMatchingPrefixesWrapper(prefixEdge, "");
		} else {
			return countMatchingPrefixesWrapper(prefixEdge, prefix.substr(1, prefix.length()-1));
		}
	}

	return 0;
}

