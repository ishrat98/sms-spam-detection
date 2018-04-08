#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int cnt=0;

    ifstream iFile;
    iFile.open("out.txt");

    string str;

    int longest=0;

    while(getline(iFile,str))
    {
        if(longest < str.length())
            longest = str.length();
        cout << str.length() << endl;
    }
    iFile.close();

    ofstream oFile;
    oFile.open("out2.txt");

    iFile.open("out.txt ");

    while(getline(iFile,str))
    {
        int l = str.length();
        if(l < longest)
        {
            string outst=str;
            int n = (longest - l)/2;
            for(int i=0; i<n; i++)
                outst += " 0";
            outst += "\n";
            oFile << outst;
        }
        else
            oFile << (str+"\n");
    }

    return 0;
}
