#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "Set.h"
//#include "MapDictionary.h"
#include "HashDictionary.h"



using namespace std;


int main(){
	string vocabulary;
	fstream cmuDictionary;
	Dictionary dictionary;
	char c[200];
	cmuDictionary.open("/tmp2/dsa2016_hw5/cmudict-0.7b",ios::in);
	
	do
	{
		cmuDictionary.getline(c,sizeof(c));
		if(isalpha(c[0])){
			istringstream dictionaryBuffer(c);
			dictionaryBuffer >> vocabulary;
			transform(vocabulary.begin(),vocabulary.end(),vocabulary.begin(),::tolower); 
		//	cout << vocabulary << endl;
			dictionary.Insert(vocabulary);
			}
		}while(!cmuDictionary.eof());

	
		//dictionary.PrintDictionary();


	bool found;
	int count;
	string inputLine,input;
	

	


	while(getline(cin,inputLine)){
		istringstream buffer(inputLine);
		buffer >> input;
		cout << input << " ==>";
	
		found = dictionary.Find(input);
		if(found){
			cout << " OK" << endl;
		}
		else{
			count = 0;
			Set set(input);


			map<string,bool>::iterator it,end;
			it = set.set2.begin();
			end = set.set2.end();
			for(;it != end;++it){
				found = dictionary.Find(it->first);
				if(found){
					cout << " " << it->first;
					count++;
				}
			}



			if(count == 0){
				cout << " NONE" << endl;
			}
			else{
				cout << endl;
			}


		}
		
		//set.PrintSet2();
		//cout << endl;
		//cout << set.size2 << endl;

	}

	


	return 0;
}










