/*
 * binaryTree.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Komani
 */

#include<iostream>


#include<math.h>
#include<list>
#include "Node.h"
#include<vector>

using namespace std;

template<class T>
class binaryTree{
	private:
		Node<T>* root;
		int dist;

	public:
		binaryTree<T>() : root(NULL), dist(0) {};

		Node<T>* getRoot() { return root; }
		void insertNode(T);

		void deleteNode(Node<T>*);
		void transplant(Node<T>*, Node<T>*);
		Node<T>* tree_minimum(Node<T>*);

		Node<T>* findNode(T);
		void deleteTree(Node<T>*);

		void makeListsAtEachLevel();
		~binaryTree<T>();

};

template<class T>
void binaryTree<T> :: insertNode(T value){
	Node<T>* curNode = root;
	Node<T>* newNode = new Node<T>(value);
	if(!newNode){
		cout<<"Memory Allocation failed."<<endl;
		return;
	}

	if(!root){
			root = newNode;
			return;
	}

	while(true){
		if(curNode->getValue() < value){
			if(!curNode->getRight()) {
				curNode->setRight(newNode);
				newNode->setParent(curNode);
				break;
			}
			curNode = curNode->getRight();
		} else {
			if(!curNode->getLeft()){
				curNode->setLeft(newNode);
				newNode->setParent(curNode);
				break;
			}
			curNode = curNode->getLeft();
		}
	}


};

template<typename T>
void binaryTree<T> :: transplant(Node<T>* u, Node<T>* v){
	if(!u->getParent()){
		root = v;
	} else if (u->getParent()->getLeft() == u){
		u->getParent()->setLeft(v);
	} else {
		u->getParent()->setRight(v);
	}

	if(v){
		v->setParent(u->getParent());
	}
}

template<typename T>
Node<T>* binaryTree<T> :: tree_minimum(Node<T>* curNode){
	while(curNode->getLeft()!=NULL){
		curNode = curNode->getLeft();
	}

	return curNode;
}

template<class T>
void  binaryTree<T> :: deleteNode(Node<T>* deleteMe){
	if(!deleteMe->getLeft()){
		transplant(deleteMe, deleteMe->getRight());
	} else if(!deleteMe->getRight()){
		transplant(deleteMe, deleteMe->getLeft());
	} else {
		Node<T>* successor = tree_minimum(deleteMe->getRight());

		if(deleteMe->getRight() != successor){
			transplant(successor, successor->getRight());
			successor->setRight(deleteMe->getRight());
			deleteMe->getRight()->setParent(successor);
		}

		transplant(deleteMe, successor);
		successor->setLeft(deleteMe->getLeft());
		deleteMe->getLeft()->setParent(successor);
	}

	delete(deleteMe);
}

template<class T>
Node<T>*  binaryTree<T> ::findNode(T value){
	Node<T>* curNode = root;

	while(true){
		if(!curNode) return NULL;

		if(curNode->getValue() == value) return curNode;
		if(curNode->getValue() < value){
			curNode = curNode->getRight(); // findNode(curNode->getRight(), value);
		} else {
			curNode = curNode->getLeft(); // findNode(curNode->getLeft(), value);
		}
	}
}

template<class T>
binaryTree<T> :: ~binaryTree(){

	deleteTree(root);
	root = NULL;
};


template<class T>
void binaryTree<T> :: deleteTree(Node<T>* start){
	if(start != NULL){

	deleteTree(start->getLeft());
	deleteTree(start->getRight());
	delete start;
	}
};

template<class T>
void binaryTree<T> :: makeListsAtEachLevel(){

	vector< list< Node<T>* > > listOfNodes;

	list< Node<T>* > nodes;
	nodes.push_back(root);
	listOfNodes.push_back(nodes);

	while(true){
		list< Node<T>* > nextLevelList;
		for(typename list< Node<T>* > :: iterator it = nodes.begin(); it != nodes.end(); ++it){
			if((*it)!=NULL){
				if((*it)->getLeft())
					nextLevelList.push_back((*it)->getLeft());

				if((*it)->getRight())
					nextLevelList.push_back((*it)->getRight());
			}
		}

		if(nextLevelList.size() == 0){
			break;
		}
		listOfNodes.push_back(nextLevelList);
		nodes = nextLevelList;
	}

	for(int i = 0; i < listOfNodes.size();++i){
		list< Node<T>* > nodesAtThisLevel = listOfNodes[i];
		for(typename list< Node<T>* > :: iterator it = nodesAtThisLevel.begin(); it != nodesAtThisLevel.end(); ++it){
			cout<<(*it)->getValue()<<" ";
		}

		cout<<endl;
	}

}
