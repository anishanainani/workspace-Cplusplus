/*
 * binaryTree.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: Komani
 */

#include<iostream>

#include "Node.h"
#include<math.h>

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
		int getHeight();
		int treeHeight(Node<T>*);

		void  preorder();
		void  preorderTraversal(Node<T>*);

		void  inorder();
		void  inorderTraversal(Node<T>*);

		void  postorder();
		void  postorderTraversal(Node<T>*);

		Node<T>* lowestCommonAncestor(Node<T>*,Node<T>*);
		Node<T>* findLowestCommonAncestor(Node<T>*,T,T);

		bool isBalanced();
		int maxDepth(Node<T>*);
		int minDepth(Node<T>*);

		Node<T>* inorderSuccessor(Node<T>*);
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
int binaryTree<T> :: getHeight(){
	return treeHeight(root);
}

template<class T>
int binaryTree<T> :: treeHeight(Node<T>* start){
	if(start == NULL) return -1;
	return 1 + fmax(treeHeight( start->getLeft() ),
					treeHeight( start->getRight() ) );
}

template<class T>
void binaryTree<T> :: preorder(){
	preorderTraversal(root);
}

template<class T>
void binaryTree<T> :: preorderTraversal(Node<T>* start){
	if(start == NULL) return;
	cout<<start->getValue()<<endl;
	preorderTraversal(start->getLeft());
	preorderTraversal(start->getRight());
}

template<class T>
void binaryTree<T> :: inorder(){
	inorderTraversal(root);
}

template<class T>
void binaryTree<T> :: inorderTraversal(Node<T>* start){
	if(start == NULL) return;
	inorderTraversal(start->getLeft());
	cout<<start->getValue()<<endl;
	inorderTraversal(start->getRight());
}

template<class T>
void binaryTree<T> :: postorder(){
	postorderTraversal(root);
}

template<class T>
void binaryTree<T> :: postorderTraversal(Node<T>* start){
	if(start == NULL) return;
	postorderTraversal(start->getLeft());
	postorderTraversal(start->getRight());
	cout<<start->getValue()<<endl;
}

template<class T>
Node<T>* binaryTree<T> :: lowestCommonAncestor(Node<T>* node1, Node<T>* node2){
	if(!node1 || !node2){
		cout<<"Nodes not found."<<endl;
		return NULL;
	}
	return findLowestCommonAncestor(root, node1->getValue(), node2->getValue());
}

template<class T>
Node<T>* binaryTree<T> :: findLowestCommonAncestor(Node<T>* start, T value1, T value2){
	if(start != NULL){
		T value = start->getValue();
		if(value > value1 && value > value2){
			return findLowestCommonAncestor(start->getLeft(), value1, value2);
		} else if(value < value1 && value < value2){
			return findLowestCommonAncestor(start->getRight(), value1, value2);
		} else {
			return start;
		}
	}
	return NULL;
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
int binaryTree<T> :: maxDepth(Node<T>* curElem){
	if(curElem == NULL) return -1;

	return 1+fmax(maxDepth(curElem->getLeft()), maxDepth(curElem->getRight()));
}

template<class T>
int binaryTree<T> :: minDepth(Node<T>* curElem){
	if(curElem == NULL) return -1;

	return 1+fmin(minDepth(curElem->getLeft()), minDepth(curElem->getRight()));
}

template<class T>
bool binaryTree<T> ::isBalanced(){
	cout<<maxDepth(root);
	cout<<minDepth(root);
	return ((maxDepth(root) - minDepth(root))<=1);
}

template<class T>
Node<T>* binaryTree<T> :: inorderSuccessor(Node<T>* curNode){

	if(!curNode) {
		cout<<"Node doesnt exist."<<endl;
		return NULL;
	}
	if(curNode->getRight()){
		return tree_minimum(curNode->getRight());
	}

	while(curNode!=NULL && curNode->getParent()->getRight()==curNode){
		curNode = curNode->getParent();
	}

	return curNode->getParent();
}