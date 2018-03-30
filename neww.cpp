#include "stemming/english_stem.h"  //import  english_stem header from the folder "Stemming"

#include<bits/stdc++.h>
using namespace std;
map <string, int>wordfreq;

bool is_in_array(const wstring &value, const vector<wstring> &array);

int main(){
     wstring theWord; //wstring means wide string. char type of wstring is wchar_t.
                    //to know more about wstring visit here:
                    //http://www.cplusplus.com/reference/string/wstring/


      vector <wstring> words; // Vector to hold our words we read in.
      vector <wstring> stopWords; //Vector to hold stop Words.
      string str; // Temp string to store words
      ifstream fin("smsDataset.txt"); // Opens the text file
      ifstream fin2("stopWords.txt");  //Opens the text file containing stopWords



    //Starts to read the stopWords.txt file and stores the stop words into a vector
      while (fin2 >> str) // Will read up to eof() and stop at every word
        {
            wstring temp;
            temp.assign(str.begin(), str.end());
            stopWords.push_back(temp);
        }



      while (fin >> str) // Will read the words of errors.txt and if a word is not in stopWords vector then the word will be stored to stem
        {
            wstring temp;
            temp.assign(str.begin(), str.end());
            if(!is_in_array(temp, stopWords))
                words.push_back(temp);
        }
        fin.close(); // Close that file!



        stemming::english_stem<> stemObj; //creating an object of english_stem class
        int i;
        for(i=0; i<words.size(); i++){
            theWord = words[i];
            wcout<<"Original word was:\t"<<theWord.c_str()<<endl; //wcout is used to print wstring. c_str() is used to convert wstring to normal "c++" string
            stemObj(theWord); //this method is stemming theWord variable and putting the stemmed word into it
            wcout<<"Stemmed word is:\t"<<theWord.c_str()<<endl<<endl; //converting the stemmed word into normal string and printing
        }

        do{
      string temp;
      name>>temp;
      wordfreq[temp]++;
    }while(name);

    cout<<endl<<"The Frequency::"<<endl;

    for(map<string,int>::iterator iter=wordfreq.begin();iter!=wordfreq.end();iter++){
      cout<<iter->first<<" : "<<iter->second<<endl;
    }


    return 0;
}


bool is_in_array(const wstring &value, const vector<wstring> &array)
{
    return find(array.begin(), array.end(), value) != array.end();
}
