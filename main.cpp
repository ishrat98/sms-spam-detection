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
	vector< map<string,int> > frequency;
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


	vector< vector <string> > tokenization;
	ifstream anotherFile;

	anotherFile.open("smsDataset.txt");


	while(getline(anotherFile,line)){
		vector<string> token;
		makeSmaller(line);

		istringstream iLine(line);
		while(iLine>>word)
		{

			token.push_back(word);
		}
		tokenization.push_back(token);
	}
	anotherFile.close();

	vector<string> :: iterator it;
	vector<string> :: iterator it2;


	for(int i=0;i<tokenization.size();i++)
	{
		for(it = tokenization[i].begin(); it!=tokenization[i].end(); it++){

			for(it2=stopWordList.begin(); it2!=stopWordList.end(); it2++){
				if(*it == *it2){

					tokenization[i].erase(it);
					it--;
				}
			}
		}
	}

	cout<<"All the words we have: "<<endl<<endl;

	for(int i=0;i<tokenization.size();i++)
	{
		map<string,int> freq;
		for(it = tokenization[i].begin(); it!=tokenization[i].end(); it++){
			freq[*it]++;
		}
		frequency.push_back(freq);
	}

	for(int i=0;i<tokenization.size();i++)
	{
		cout<<"for message "<<i+1<<endl;
		for(map<string,int>::iterator iter=frequency[i].begin();iter!=frequency[i].end();iter++){
			cout<<iter->first<<" --> "<<iter->second<<endl;
		}

	}


	return 0;
}
