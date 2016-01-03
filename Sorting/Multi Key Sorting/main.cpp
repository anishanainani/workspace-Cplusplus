/*
 * main.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: Komani
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class name{
	public:
		name(string f, string l) : first_name(f), last_name(l){};
		string getFirstName(){ return first_name;}
		string getLastName(){ return last_name;}
		void setFirstName(string f){ first_name = f; }
		void setLastName(string l){ last_name = l; }
	private:
		string first_name;
		string last_name;
};


bool comparator(name name1, name name2){
	int ret = name1.getFirstName().compare(name2.getFirstName());

	if(ret==0){
		ret = name1.getLastName().compare(name2.getLastName());
		if(ret<0){
			return true;
		}

		return false;
	}

	if(ret<0){
		return true;
	}

	return false;

}

int main(){
	vector<name> names;
	for(int i = 0; i < 5; ++i){
		string f,l;
		cout<<"First name : ";
		cin>>f;

		cout<<"Last Name : ";
		cin>>l;

		names.push_back(name(f,l));
	}

	sort(names.begin(), names.end(), comparator);

	for(int i = 0; i < 5; ++i){
			cout<<"First name : ";
			cout<<names[i].getFirstName()<<" : ";

			cout<<"Last Name : ";
			cout<<names[i].getLastName()<<endl;
	}

	return 0;
}


