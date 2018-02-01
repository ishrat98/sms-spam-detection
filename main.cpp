#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;



int main(){
	vector<string> stopWordList;
	ifstream iFile;
	iFile.open("stopWord.txt");
	string line,word;

	while(getline(iFile,line)){

		istringstream iLine(line);
		while(iLine>>word){
			stopWordList.push_back(word);
			//cout<<word<<endl;

		}
	}
	iFile.close();
	vector <string> tokens;
	//ifstream inputFile;
	iFile.open("file.txt");
	//string lines,words;

	while(getline(iFile,line)){
		istringstream inputLine(line);
//		cleanUp(line);
		while(inputLine>>word){
		//while(getline(cin,words)){
			tokens.push_back(word);


		}

	}
	iFile.close();

	vector<string> :: iterator it;
	vector<string> :: iterator it2;


	for(it = tokens.begin(); it!=tokens.end(); it++){
		for(it2=stopWordList.begin(); it2!=stopWordList.end(); it2++){
			if(*it == *it2){
				tokens.erase(it);
			}
		}
	}
	cout<<" after removing stopWord"<<endl;
	for(it = tokens.begin(); it!=tokens.end(); it++){
		cout<<*it<<endl;
	}

}
