#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void makeSmaller(string &word){

	for(int i=0;i<word.length();i++)
		{
			if(word[i]>='A' && word[i]<='Z'){

				word[i] = word[i]+32;
		}

	}
}

int main(void)
{
	vector<string> stopWordList;
	ifstream iFile;
	iFile.open("stopWord.txt");
	string line,word;

	while(getline(iFile,line)){
		makeSmaller(line);
		istringstream iLine(line);
		while(iLine>>word){

			stopWordList.push_back(word);


		}
	}


	iFile.close();


	vector <string> tokenization;
	ifstream anotherFile;

	anotherFile.open("smsDataset.txt");


	while(getline(anotherFile,line)){

		makeSmaller(line);

		istringstream iLine(line);
		while(iLine>>word)
		{

			tokenization.push_back(word);


		}

	}
	anotherFile.close();

	vector<string> :: iterator it;
	vector<string> :: iterator it2;

	for(it = tokenization.begin(); it!=tokenization.end(); it++){
		for(it2=stopWordList.begin(); it2!=stopWordList.end(); it2++){
			if(*it == *it2){

				tokenization.erase(it);
				it--;

			}
		}
	}

	for(it = tokenization.begin(); it!=tokenization.end(); it++){
		cout << *it << endl;
	}

}
