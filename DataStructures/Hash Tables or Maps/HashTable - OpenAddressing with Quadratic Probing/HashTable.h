/*
 * HashTable.h
 *
 *  Created on: Jan 23, 2015
 *      Author: Komani
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include<iostream>
#include<vector>
#include<algorithm>
#include "EmployeeTelephoneRecords.h"

using namespace std;

template<typename HashedObj, typename Key, typename Value>
class HashTable{
	public:

		enum HashFlag{ ACTIVE, EMPTY, DELETED};
		typedef struct HashTableElement{
			HashedObj element;
			HashFlag flag;
			HashTableElement(const HashedObj &x = HashedObj("",0), HashFlag f = EMPTY) : element(x), flag(f){};

		} HashTableElement;

		HashTable(int size = 101) : currentSize(0){ HashedEntry.assign(size,HashTableElement());};
		bool contains(Key);
		void insert(Key, Value);
		void remove(Key key);
		HashedObj* searchValue(Key key);
		int hashFunction(Key, int);
		int hash(Key);
		void makeEmpty();
		void reHash();
		bool isPrime(int);
		int nextPrime(int);
		Value operator[](Key key) {return searchValue(key)->getValue();};


	private:
		vector< HashTableElement> HashedEntry ;
		int currentSize;
};

template<typename HashedObj, typename Key, typename Value>
bool HashTable<HashedObj, Key, Value> :: contains(Key key) {
	for(int i = 0; HashedEntry[hashFunction(key, i)].flag != EMPTY; i++){
		if(HashedEntry[hashFunction(key, i)].element.getKey() == key){
			return true;
		}
	}
	return false;
}

template<typename HashedObj, typename Key, typename Value>
void HashTable<HashedObj, Key, Value> :: insert(Key key, Value value) {
	int i=0;

	for(i = 0; HashedEntry[hashFunction(key, i)].flag != EMPTY && HashedEntry[hashFunction(key, i)].flag != DELETED; i++){

		if(HashedEntry[hashFunction(key, i)].element.getKey() == key){
			cout<<"Key already exists"<<endl;
			return;
		}
	}

	HashedEntry[hashFunction(key, i)].element = HashedObj(key, value);
	HashedEntry[hashFunction(key, i)].flag = ACTIVE;
	if(++currentSize == HashedEntry.size()){
		reHash();
	}
	cout<<"Insertion Successful"<<endl;
}

template<typename HashedObj, typename Key, typename Value>
void HashTable<HashedObj, Key, Value> :: remove(Key key) {
	for(int i = 0; HashedEntry[hashFunction(key, i)].flag != EMPTY || HashedEntry[hashFunction(key, i)].flag == DELETED; i++){
		HashTableElement & curElement = HashedEntry[hashFunction(key, i)];
		if(curElement.element.getKey() == key){
			curElement.element.setKey("");
			curElement.element.setValue(0);
			curElement.flag = DELETED;
			cout<<"Delete Successful"<<endl;
			--currentSize;
			return;
		}
	}
	cout<<"Delete Unsuccessfull."<<endl;

}

template<typename HashedObj, typename Key, typename Value>
HashedObj* HashTable<HashedObj, Key, Value> :: searchValue(Key key) {
	for(int i = 0; HashedEntry[hashFunction(key, i)].flag != EMPTY; i++){
		if(HashedEntry[hashFunction(key, i)].element.getKey() == key){
			return &HashedEntry[hashFunction(key, i)].element;
		}

	}
	return NULL;
}

template<typename HashedObj, typename Key, typename Value>
int HashTable<HashedObj, Key, Value> :: hashFunction(Key key, int i) {
	int hashValue = hash(key) + i*i;
	hashValue%=HashedEntry.size();
	if(hashValue < 0)
		hashValue+=HashedEntry.size();

	if(hashValue >= HashedEntry.size())
			hashValue-=HashedEntry.size();
	return hashValue;

}

template<typename HashedObj, typename Key, typename Value>
int HashTable<HashedObj, Key, Value> :: hash(Key key) {
	int hashValue = 0;
	for(int i = 0; i < key.length(); i++){
		hashValue = 37*hashValue + key[i];
	}

	return hashValue;
}

template<typename HashedObj, typename Key, typename Value>
void HashTable<HashedObj, Key, Value> :: makeEmpty(){

	for(int i = 0; i < HashedEntry.size(); i++){
		HashedEntry[i].flag = EMPTY;
	}
	currentSize = 0;
};

template<typename HashedObj, typename Key, typename Value>
void HashTable<HashedObj, Key, Value> :: reHash(){

	vector<HashTableElement> oldHashedEntry = HashedEntry;

	makeEmpty();
	HashedEntry.resize(nextPrime(2*HashedEntry.size()));
	for(int i = 0; i < oldHashedEntry.size(); i++){
		if(oldHashedEntry[i].flag == ACTIVE){
			insert(oldHashedEntry[i].element.getKey(), oldHashedEntry[i].element.getValue());
		}
	}
};

template<typename HashedObj, typename Key, typename Value>
bool HashTable<HashedObj, Key, Value> :: isPrime(int num){
	for(int j = 2; j < num; j++){
		if(num%j == 0){
			return false;
		}
	}

	return true;
};

template<typename HashedObj, typename Key, typename Value>
int HashTable<HashedObj, Key, Value> :: nextPrime(int n){
	int i;
	for(i = n; !isPrime(i); i++){}
	return i;
}

#endif /* HASHTABLE_H_ */
