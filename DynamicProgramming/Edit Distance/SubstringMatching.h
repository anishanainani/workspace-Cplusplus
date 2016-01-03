/*
 * SubstringMatching.h
 *
 *  Created on: Feb 6, 2015
 *      Author: Komani
 */

#ifndef SUBSTRINGMATCHING_H_
#define SUBSTRINGMATCHING_H_

#include<iostream>

using namespace std;

class SubstringMatching{

	public:
	SubstringMatching(string s, string t){
			this->s = s;
			this->t = t;
		};
		int substring_match();
		void row_init();
		void column_init();
		int match(char, char);
		int insert_delete(char);
		void goal_cell(int*, int*);
		void reconstruct_path();
		void do_reconstruct_path(int, int);
		void match_out(int, int);
		void insert_out(int, int);
		void delete_out(int, int);

	private:
		enum{ MATCH, INSERT, DELETE};
		string s, t;
		typedef struct{ int cost; int parent;} cell;
		cell sc[50][50];
};

int SubstringMatching :: substring_match(){
	int opt[3];

	row_init();
	column_init();

	int i,j;

	for(i = 1; i <= s.length(); ++i){
		for(j = 1; j <= t.length(); ++j){
				opt[MATCH] = sc[i-1][j-1].cost + match(s[i-1], t[j-1]);
				opt[INSERT] = sc[i][j-1].cost + insert_delete(t[j-1]);
				opt[DELETE] = sc[i-1][j].cost + insert_delete(s[i-1]);

				sc[i][j].cost = opt[MATCH];
				sc[i][j].parent = MATCH;
				for(int k = INSERT; k <=DELETE; ++k){
					if(opt[k] < sc[i][j].cost) {
						sc[i][j].cost = opt[k];
						sc[i][j].parent = k;
					}
				}

		}
	}

	goal_cell(&i, &j);

	for(int p = 0; p <= s.length(); ++p){
		for(int q = 0; q <= t.length(); ++q){
			cout<<sc[p][q].cost<<" ";
		}
		cout<<endl;
	}
	return sc[i][j].cost;
};

void SubstringMatching :: row_init(){
	for(int i = 0; i <= t.length(); i++){
		sc[0][i].cost = 0;
		sc[0][i].parent = -1;
	}
}

void SubstringMatching :: column_init(){
	for(int i = 0; i <= s.length(); i++){
		sc[i][0].cost = i;
		if(i==0){
			sc[i][0].parent = -1;
		} else {
			sc[i][0].parent = DELETE;
		}
	}
}

int SubstringMatching :: match(char c, char d){
	if(c==d) return 0;
	else return 1;
}

int SubstringMatching :: insert_delete(char c){
	return 1;
}

void SubstringMatching :: goal_cell(int* i, int* j){

	*i = s.length();
	*j = 0;

	for(int k = 1; k <= t.length(); ++k){
		if(sc[*i][k].cost < sc[*i][*j].cost)
			*j = k;
	}

}

void SubstringMatching :: reconstruct_path(){
	do_reconstruct_path(s.length(), t.length());
}

void SubstringMatching :: do_reconstruct_path(int i, int j){
	if(sc[i][j].parent == -1) return;

	if(sc[i][j].parent == MATCH){
		do_reconstruct_path(i-1, j-1);
		match_out(i, j);
	}


	if(sc[i][j].parent == INSERT){
		do_reconstruct_path(i, j-1);
		insert_out(i, j);
	}


	if(sc[i][j].parent == DELETE){
		do_reconstruct_path(i-1, j);
		delete_out(i, j);
	}
};

void SubstringMatching :: match_out(int i, int j){
	if(s[i-1] == t[j-1])
	cout<<"M ";
	else cout<<"S ";
};

void SubstringMatching :: insert_out(int i, int j){
	cout<<"I ";
}

void SubstringMatching :: delete_out(int i, int j){
	cout<<"D ";
}

#endif /* SUBSTRINGMATCHING_H_ */
