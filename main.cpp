#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void makeSmaller(string &s){
	int i=0;
	while(i!=s.length()){
		if(s[i]>='A' && s[i]<='Z'){
            s[i] = s[i]+32;
		}
		else if(s[i]<'A' || (s[i]>'Z' && s[i]<'a') || s[i]>'z'){
			s[i]=' ';

		}
		i++;
	}
}

int main(void)
{
	map<string,int> frequincy;
	vector<string> stopWordList;
	ifstream iFile;
	iFile.open("stopWord.txt");
	string line,word;

	while(getline(iFile,line)){
		makeSmaller(line);
		istringstream iLine(line);
		while(iLine>>word){

			stopWordList.push_back(word);
			//cout<<"stop word: "<<word<<endl;


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

	cout<<"All the words we have: "<<endl<<endl;
	for(it = tokenization.begin(); it!=tokenization.end(); it++){
		frequincy[*it]++;
	}

	for(map<string,int>::iterator iter=frequincy.begin();iter!=frequincy.end();iter++){
		cout<<iter->first<<" --> "<<iter->second<<endl;
	}



}
