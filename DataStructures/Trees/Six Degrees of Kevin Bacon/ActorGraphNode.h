/*
 * ActorGraphNode.h
 *
 *  Created on: Jan 25, 2015
 *      Author: Komani
 */

#ifndef ACTORGRAPHNODE_H_
#define ACTORGRAPHNODE_H_


#include<iostream>
#include<unordered_set>

using namespace std;

template<typename nodeType>
class ActorGraphNode{
	public:
		ActorGraphNode(nodeType node) : nodeValue(node){};
		nodeType getNodeValue() { return nodeValue; };
		unordered_set<nodeType>& getLinkedActors() { return linkedActors; }
	private:
		nodeType nodeValue;
		unordered_set<nodeType> linkedActors;
};




#endif /* ACTORGRAPHNODE_H_ */
