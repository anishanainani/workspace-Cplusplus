#include<iostream>
#include<vector>

using namespace std;

void findPermutations(vector<int> soFar, vector<int> rest){

	if(rest.size() == 0){
		for(vector<int> :: iterator it = soFar.begin(); it!=soFar.end();++it)
			cout<<*it<<" ";
		cout<<endl;
		return;
	}

	for(unsigned i = 0; i < rest.size(); ++i){
		vector<int> temp_rest, temp_soFar(soFar);

		temp_soFar.push_back(rest[i]);

		temp_rest.insert(temp_rest.begin(), rest.begin(), rest.begin()+i);
		temp_rest.insert(temp_rest.end(), rest.begin()+i+1, rest.end());

		findPermutations(temp_soFar, temp_rest);

		temp_rest.clear();
		temp_soFar.clear();
	}
};

void printPermutations(vector<int> & input){
	vector<int> soFar;
	findPermutations(soFar, input);
};

int main(){
	int arr[] = {1,2,3};
	vector<int> input(arr, arr+3);

	printPermutations(input);
	return 0;
}

