#include<iostream>
#include<vector>

using namespace std;

void findCombinations(vector<int> soFar, vector<int> rest){

	if(rest.size() == 0){
		for(vector<int> :: iterator it = soFar.begin(); it!=soFar.end();++it)
			cout<<*it<<" ";
		cout<<endl;
		return;
	}

	else {
		vector<int> temp_rest, temp_soFar(soFar);

		temp_soFar.push_back(rest[0]);

		temp_rest.insert(temp_rest.begin(), rest.begin()+1, rest.end());

		findCombinations(temp_soFar, temp_rest);
		findCombinations(soFar, temp_rest);

		temp_rest.clear();
		temp_soFar.clear();
	}
};

void printCombinations(vector<int> & input){
	vector<int> soFar;
	findCombinations(soFar, input);
};

int main(){
	int arr[] = {1,2,3, 4};
	vector<int> input(arr, arr+4);

	printCombinations(input);
	return 0;
}

