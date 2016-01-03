/*
 * stackElement.h
 *
 *  Created on: Jan 15, 2015
 *      Author: Komani
 */

#ifndef STACKELEMENT_H_
#define STACKELEMENT_H_

#include<iostream>

using namespace std;
template<class T>
class stackElement{
	private:
		stackElement<T>* nextElem;
		T val;

	public:
		stackElement(){}
		stackElement( T data) : nextElem(NULL), val(data){}
		stackElement<T>* next() { return nextElem;}
		T value(){ return val; }
		void setNext(stackElement<T>* n) { nextElem = n; }
		void setValue(T data) { val = data; }
};



#endif /* STACKELEMENT_H_ */
