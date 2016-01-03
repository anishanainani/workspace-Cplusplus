#include<iostream>
#include<queue>

typedef struct v{
	int value;
	struct v* next;
} vertex;

typedef struct{
	int numberOfVertices;
	int numberOfEdges;
	vertex* list;
} graph;


using namespace std;


graph* inputGraph(){
	graph* g = new graph;
	int nv;
	cout<<"Enter number of vertices : ";
	cin>>nv;
	g->numberOfVertices = nv;
	g->list = new vertex[nv];

	for(int i = 0; i < nv; i++){
		g->list[i].value = i+1;
		g->list[i].next = NULL;
	};

	int ne;
	cout<<"Enter number of edges : ";
	cin>>ne;
	g->numberOfEdges = ne;

	for(int i = 0; i < ne; i++){
		int v1, v2;
		cout<<"Enter edge "<<(i+1)<<" : ";
		cin>>v1>>v2;
		if(v1>nv || v2>nv){
			cout<<"Invalid Edge!!"<<endl;
			i--;
		}else{
			vertex *temp = &g->list[v1-1];
			while(temp->next != NULL){
				temp= temp->next;
			}
			vertex *v = new vertex; v->value = v2;v->next = NULL;
			temp->next = v;

			if(v1!=v2){
				temp = &g->list[v2-1];
				while(temp->next != NULL){
					temp = temp->next;
				}
				vertex* vt = new vertex; vt->value = v1;vt->next=NULL;
				temp->next = vt;
			}
		}
	}

	return g;
}

void printAdjacancyList(graph* g){

	for(int i = 0; i<g->numberOfVertices; i++){
			cout<<g->list[i].value<<" - ";
			vertex* v= g->list[i].next;
			while(v!=NULL){
				cout<<v->value<<" ";
				v=v->next;
			}
			cout<<endl;
	}
}

void BFS(graph* g, int start){

	//initializing search
	bool* processed = new bool[g->numberOfVertices];
	bool* discovered = new bool[g->numberOfVertices];
	int* parent = new int[g->numberOfVertices];

	for(int i =0; i < g->numberOfVertices; i++){
		processed[i] = false;
		discovered[i] = false;
		parent[i] = -1;
	}

	queue<int> q;
	int v;
	q.push(start);

	discovered[start-1] = true;

	while(q.empty() == false){
		v = q.front();
		q.pop();
		processed[v-1] = true;
		cout<<v;

		if(v==start){
			cout<<endl;
		}
		if(parent[v-1] != -1)
		cout<<"("<<parent[v-1]<<"-"<<v<<")"<<endl;

		vertex* p = &g->list[v-1];
		while(p->next != NULL){
			vertex* t = p->next;
			if(discovered[(t->value)-1]==false){
				q.push(t->value);
				discovered[(t->value)-1] = true;
				parent[(t->value)-1] = v;
			}
			p=t;
		}
	}
}

int main(){
	graph* gh = inputGraph();

	cout<<"Printing Adjacency list :"<<endl;
	printAdjacancyList(gh);

	cout<<"BFS Traversal : "<<endl;
	BFS(gh, 1);
}
