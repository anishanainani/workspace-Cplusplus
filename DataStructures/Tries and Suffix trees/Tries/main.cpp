/*
 * main.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Anisha
 */

#include<iostream>
#include "trie.h"
#include "node.h"
#include<fstream>

using namespace std;

int main(){

	ifstream f("dictionary.txt");
	if(f.fail()){
		cout<<"Error : File cannot be opened"<<endl;
		return 0;
	}

	trie* t = new trie();

	while(f){
		string word;
		f>>word;
		t->addWord(word);
	}

	//t->display(t->getRoot()->getEdges());

	//cout<<t->countMatchingWords("komal")<<endl;
	//cout<<t->countMatchingWords("jyoti")<<endl;

	cout<<t->countMatchingPrefixes("A")<<endl;

	if(t->countMatchingWords("ABBREVIATES") >0){
		cout<<"Word present"<<endl;
	}

	return 0;
}



