/*
 * TelephoneWords.h
 *
 *  Created on: Feb 2, 2015
 *      Author: Komani
 */

#ifndef TELEPHONEWORDS_H_
#define TELEPHONEWORDS_H_

#include<iostream>

using namespace std;

class TelephoneWords{
	private:
		int* inputArray;
		string out;

	public:
		TelephoneWords(int * in) : inputArray(in), out(""){};
		void telephoneWords(int);
		char getCharKey(int telephoneKey, int place);
};

void TelephoneWords :: telephoneWords(int index){

	if(index>6){
		cout<<out<<endl;
		return;
	}

	for(int i = 1; i <=3; ++i){

		out+=getCharKey(inputArray[index], i);
		telephoneWords(index+1);
		out.resize(out.length()-1);
		if(inputArray[index] == 0 || inputArray[index] == 1) return;

	}
};

char TelephoneWords :: getCharKey(int telephoneKey, int place){
	switch(telephoneKey){
		case 0: return '0';
		case 1: return '1';
		case 2: if(place == 1) return 'A';
				else if(place == 2) return 'B';
				else if(place == 3) return 'C';
				break;
		case 3: if(place == 1) return 'D';
				else if(place == 2) return 'E';
				else if(place == 3) return 'F';
				break;
		case 4: if(place == 1) return 'G';
				else if(place == 2) return 'H';
				else if(place == 3) return 'I';
				break;
		case 5: if(place == 1) return 'J';
				else if(place == 2) return 'K';
				else if(place == 3) return 'L';
				break;
		case 6: if(place == 1) return 'M';
				else if(place == 2) return 'N';
				else if(place == 3) return 'O';
				break;
		case 7: if(place == 1) return 'P';
						else if(place == 2) return 'R';
						else if(place == 3) return 'S';
						break;
		case 8: if(place == 1) return 'U';
						else if(place == 2) return 'V';
						else if(place == 3) return 'W';
						break;

		case 9: if(place == 1) return 'X';
						else if(place == 2) return 'Y';
						else if(place == 3) return 'Z';
						break;
	}
}



#endif /* TELEPHONEWORDS_H_ */
