/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */
/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */

/*
 * main.cpp
 *
 *  Created on: Feb 18, 2015
 *      Author: Komani
 */


#include<iostream>
#include<vector>

using namespace std;
int count = 0;

void calculate(int i){

	if(i < 0) return;
	if(i==0) ++count;

	if((i-25) >=0) calculate(i-25);
	if((i-10) >=0) calculate(i-10);
	if((i-5) >=0) calculate(i-5);
	if((i-1) >=0) calculate(i-1);
};

int main(){

	calculate(14);
	cout<<count;
	return 0;
}






