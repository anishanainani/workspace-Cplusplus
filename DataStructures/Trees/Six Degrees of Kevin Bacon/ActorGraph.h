/*
 * ActorGraph.h
 *
 *  Created on: Jan 25, 2015
 *      Author: Komani
 */

#ifndef ACTORGRAPH_H_
#define ACTORGRAPH_H_


#include<iostream>
#include<vector>
#include<list>
#include "ActorGraphNode.h"

using namespace std;

template<typename nodeType>
class ActorGraph{
	private:
		vector< ActorGraphNode > linkedActors;
};




#endif /* ACTORGRAPH_H_ */
