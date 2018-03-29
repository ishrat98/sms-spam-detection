#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

#include "english_stem.h"  


using namespace std;

/*bool is_in_array(const wstring &value, const vector<wstring> &array)
{
    return find(array.begin(), array.end(), value) != array.end();
};*/

void makeSmaller(string &word){

	for(int i=0;i<word.length();i++)
		{
			if(word[i]>='A' && word[i]<='Z'){

				word[i] = word[i]+32;
		}

	}
}

void printFrequency(string &str, char array[10000][10000], char array2[10000][10000])
		{
			c,coun ,j,k = 0;

			int countSpace = 0;

			for(int i=0;str[i]!='\0';i++){

				if(str[i]==' '){

				    countSpace++;
			}
		}
		 //printf("Total spaces in st are %d\n", countSpace);


		 for(int i =0; i <= countSpace; i++)
		 {

		 while(j<=countSpace)
		 {
			if(i==j)
			{
				strcpy(array2[k],array[i]);

				k++;

				coun++;

				break;
			}
			else{
				    if (strcmp(array2[j],array[i]) !=0)
				    {
				    j++;

				    continue;

				    }
				else

				    break;
			}
		}
		 }
		 for(int i = 0; i < coun-1 ; i++)
		 {
			 j =0;

			 while(j <= countSpace)
		 {
			 if(strcmp(array2[i],array[j])==0)


			 c++;

			 j++;

		 }

		cout << array2[i] << " --> "<< c << "time(s)" << endl;
		c=0;

		 }
		 cout<<endl;
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

	/*for(it = tokenization.begin(); it!=tokenization.end(); it++){
		cout << *it << endl;
	}*/
	
	
	stemming::english_stem<> stemObj; //creating an object of english_stem class
    int i;
    for(i=0; i<it.size(); i++){
            theWord = it[i];
            wcout<<"Original word was:\t"<<theWord.c_str()<<endl; //wcout is used to print wstring. c_str() is used to convert wstring to normal "c++" string
            stemObj(theWord); //this method is stemming theWord variable and putting the stemmed word into it
            wcout<<"Stemmed word is:\t"<<theWord.c_str()<<endl<<endl; //converting the stemmed word into normal string and printing
        }
        
        
    printFrequency(str,array,array2);
         
         
    return 0;

}
