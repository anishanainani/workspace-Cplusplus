/*
 * HashTable.cpp
 *
 *  Created on: Jan 22, 2015
 *      Author: Komani
 */

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include "EmployeeTelephoneRecords.cpp"
using namespace std;

template<typename HashedObj, typename Key>
class HashTable{
	public:

		HashTable(int size = 101) : currentSize(size){
			theLists.reserve(101);
		};

		bool contains(HashedObj &) ;
		HashedObj* searchValue(Key);
		void makeEmpty();
		void insert( HashedObj &);
		void remove(HashedObj &);
		void reHash();
		int hashFunction(Key);
		int hash(Key);

	private:
		vector< list<HashedObj> > theLists; // vector of lists for the keys hashed to same bucket
		int currentSize;
};

template<typename HashedObj, typename Key>
bool HashTable<HashedObj, Key> :: contains(HashedObj & x){
	if(theLists.size()!=0){
		list<HashedObj> & whichList = theLists[hashFunction(x.getKey())];
		return find(whichList.begin(), whichList.end(), x) != whichList.end();
	}
	return false;
};

template<typename HashedObj, typename Key>
HashedObj* HashTable<HashedObj, Key> :: searchValue(Key key){
	 list<HashedObj>& whichList = theLists[hashFunction(key)];

	for(typename list<HashedObj> :: iterator itr = whichList.begin(); itr!=whichList.end(); ++itr){

		if((&(*itr))->getKey() == key){
			return &(*itr);
		}
		itr++;
	}

	return NULL;
}

template<typename HashedObj, typename Key>
void HashTable<HashedObj,Key> :: makeEmpty(){
	for(int i = 0; i < theLists.size(); i++){
		theLists[i].clear();
	}
};

template<typename HashedObj, typename Key>
void HashTable<HashedObj,Key> :: insert( HashedObj & x){
	if(contains(x)){
		cout<<"Element Already exists"<<endl;
		return;
	}


	theLists[50].push_back(x);

	if(++currentSize > theLists.size()){
		reHash();
	}

};

template<typename HashedObj, typename Key>
void HashTable<HashedObj, Key> :: remove(HashedObj & x){
	int hashValue = hashFunction(x);
	const list<HashedObj>& whichList = theLists[hashValue];

	list<HashedObj> itr = find(whichList.begin(), whichList.end(), x);

	if(itr == whichList.end()){
		cout<<"Element does not exist."<<endl;
		return;
	}

	whichList.erase(itr);
	--currentSize;

};

template<typename HashedObj, typename Key>
void HashTable<HashedObj, Key> :: reHash(){
	vector< list<HashedObj> > oldLists = theLists;


	for(int i = 0; i < theLists.size(); i++){
			theLists[i].clear();
	}
	currentSize = 0;

	theLists.resize(2*theLists.size());

	for(int i = 0; i < oldLists.size(); i++){
		typename list<HashedObj>::iterator itr = oldLists[i].begin();
		while(itr!=oldLists[i].end()){
			insert(*itr++);
		}
	}
};

template<typename HashedObj, typename Key>
int HashTable<HashedObj,Key> :: hashFunction(Key key){
	int hashValue = hash(key);

	hashValue %= theLists.size();
	if(hashValue < 0){
		hashValue += theLists.size();
	}

	return hashValue;
};

template<typename HashedObj, typename Key>
int HashTable<HashedObj,Key> :: hash(Key key){

	int hashValue = 0;
	for(int i = 0; i < key.length(); i++){
		hashValue = 37*hashValue + key[i];
	}

	return hashValue;
};

#endif
