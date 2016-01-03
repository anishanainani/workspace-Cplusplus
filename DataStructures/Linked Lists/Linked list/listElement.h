/*
 * lists.h
 *
 *  Created on: Jan 13, 2015
 *      Author: Komani
 */

#ifndef LISTS_H_
#define LISTS_H_

#include<iostream>

using namespace std;

template<class T>
class listElement{
private:
		listElement<T>* next;
		T data;

	public:
		listElement(const T & value) : next(NULL), data(value){};
		~listElement();
		listElement<T> *getNext(){return next;}
		const T &value() const{ return data;}
		void setNext(listElement<T> *n){ next = n;}
		void setValue(const T& value){data = value;}


};

#endif /* LISTS_H_ */
