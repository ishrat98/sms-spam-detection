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
    map<string,int>  totalWordfrequency;
	map<string,int>  hamWordfrequency;
	map<string,int>  spamWordfrequency;
    map<string,double>  hamWordProbability;
	map<string,double>  spamWordProbability;


	vector<string> stopWordList;
	set<string> uniqueWords;

	int numberOfLines;
    string classType;

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
	vector< vector <string> > testList;
	ifstream anotherFile;

	anotherFile.open("smsDataset.txt");
    anotherFile>>numberOfLines;
    getline(anotherFile,line);
    int currentNum=0;
	while(getline(anotherFile,line)){
		vector<string> token;
		makeSmaller(line);

		istringstream iLine(line);
		while(iLine>>word)
		{
			token.push_back(word);
		}
		if(currentNum< (numberOfLines*90.0)/100.0)
            tokenization.push_back(token);
        else testList.push_back(token);
		currentNum++;
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

	for(int i=0;i<testList.size();i++)
	{
		for(it = testList[i].begin(); it!=testList[i].end(); it++){

			for(it2=stopWordList.begin(); it2!=stopWordList.end(); it2++){
				if(*it == *it2){

					testList[i].erase(it);
					it--;
				}
			}
		}
	}
   // cout<<"ekhane"<<endl;
	//cout<<"All the words we have: "<<endl<<endl;

	for(int i=0;i<tokenization.size();i++)
	{
		//map<string,int> freq;
		classType = tokenization[i][0];
		for(int j = 1; j<tokenization[i].size(); j++){
			//freq[tokenization[i][j]]++;
			if(uniqueWords.find(tokenization[i][j])==uniqueWords.end()) uniqueWords.insert(tokenization[i][j]);
			if(classType=="ham") hamWordfrequency[tokenization[i][j]]++;
			else spamWordfrequency[tokenization[i][j]]++;
			totalWordfrequency[tokenization[i][j]]++;
		}
		//frequency.push_back(freq);
	}
	set<string>:: iterator it1;;
 	for( it1= uniqueWords.begin();it1!=uniqueWords.end();it1++)
	{
		//map<string,int> freq;
		//classType = tokenization[i][0];
        hamWordProbability[*it1] = hamWordfrequency[*it1]/(double)totalWordfrequency[*it1];
        spamWordProbability[*it1] = spamWordfrequency[*it1]/(double)totalWordfrequency[*it1];
		//frequency.push_back(freq);
	}

/*
	for(int i=0;i<tokenization.size();i++)
	{
		cout<<"for message "<<i+1<<endl;
		for(map<string,int>::iterator iter=frequency[i].begin();iter!=frequency[i].end();iter++){
			cout<<iter->first<<" --> "<<iter->second<<endl;
		}

	}
*/
    for(int i=0;i<testList.size();i++)
    {
        string actualClass = testList[i][0];
        double hamProbability=1.0;
        double spamProbability=1.0;
        for(int j=0;j<testList[i].size();j++)
        {
            if(uniqueWords.find(testList[i][j])==uniqueWords.end()) continue;
            hamProbability*= hamWordProbability[testList[i][j]];
            spamProbability*= spamWordProbability[testList[i][j]];
        }
        if(hamProbability>spamProbability) cout<<"ham"<<endl;
        else cout<<"spam"<<endl;
    }

	return 0;
}
