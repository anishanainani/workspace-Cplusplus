/*
 * BFS.cpp
 *
 *  Created on: Jan 9, 2015
 *      Author: Komani
 */

#include "graph.h"
#include<iostream>
#include<queue>

using namespace std;

class BFS{
	graph gr;
	bool* processed = NULL;
	bool* discovered = NULL;
	int* parent = NULL;

	public:
		BFS(){};
		BFS(graph &g){	gr = g;};

		void initialize_search(){
			processed = new bool[gr.nvertices+1];
			discovered = new bool[gr.nvertices+1];
			parent = new int[gr.nvertices+1];

			for(int i = 1; i <= gr.nvertices; i++){
				processed[i] = false;
				discovered[i] = false;
				parent[i] = -1;
			}
		}

		void bfs_traversal(int start){

			initialize_search();
			queue<int> q;
			int v;
			q.push(start);

			discovered[start] = true;

			while(q.empty() == false){
						v = q.front();
						q.pop();
						process_vertex_early(v);
						processed[v] = true;

						vertex* p = gr.edges[v];
						while(p != NULL){
							vertex* t = p;

							if(processed[(t->value)]==false || gr.directed){
								process_edge(v, t->value);
							}

							if(discovered[(t->value)]==false){
								q.push(t->value);
								discovered[(t->value)] = true;
								parent[(t->value)] = v;
							}
							p=p->next;

						}

						process_vertex_late(v);
			}
		}

		void process_vertex_early(int v){
			cout<<v<<endl;
		}

		void process_vertex_late(int v){

		}

		void process_edge(int v, int y){
			cout<<"("<<v<<" , "<<y<<")"<<endl;
		}

		void connected_components(){
			int c = 0;
			initialize_search();
			for(int i = 1; i <= gr.nvertices; i++){
				if(discovered[i]==false){
					c++;
					cout<<"Component : "<<c<<endl;
					bfs_traversal(i);
				}
			}

		}

		void find_path(int start, int end){
			cout<<"gg";
			if(start==end || end==-1) cout<<start<<" ";

			find_path(start, parent[end]);
			cout<<end<<" ";

		}

};


