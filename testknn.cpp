#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

const int h = 30;
int N;
int K=5;

#define columnSize 23

struct data{
    int col[h];

};


vector <data> sp, ns;

void clearString(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',')s[i] = ' ';
    }
}

int classifier;

void readFile(){

    srand(time(NULL));

    ifstream f("out2.txt");
    string s;

    N = 1;

    map <int, int> spam, ham;

    while(getline(f, s)){

        clearString(s);

        istringstream iss(s);

        int ham = 0;

        double d;

        data dd;
        while(iss >> d){

            dd.col[ham++] = d;

        }
        spam[ (int)dd.col[N - 1]]++;

        ns.push_back(dd);
    }
    int trainData = 0;
    classifier = spam.size();

    for( map<int,int>::iterator it = spam.begin(); it != spam.end(); it++){
        ham[it -> first] = it -> second * 9;
        ham[it -> first] /= 10;

        trainData += ham[it -> first];
    }

    //cout << "Total Size: " << v1.size() << endl;

    while(true){
        if(!trainData)break;
        int val = rand() % ns.size();

        if(ham[(int)ns[val].col[N - 1]]){
            sp.push_back(ns[val]);

            ham[(int)ns[val].col[N - 1]]--;

            ns.erase(ns.begin() + val);
            trainData--;
        }
    }
   // cout << v1.size();


}

double distan(data a, data b){
    double dis = 0.0;
    for(int j = 0; j < columnSize; j++){
        dis += (a.col[j] - b.col[j]) * (a.col[j] - b.col[j]) * 1.0;
    }
    return dis;
}

int KNN(data d){

    priority_queue <pair <double, int> , vector < pair <double, int> >, greater < pair <double, int> > > pq;

    for(int i = 0; i < sp.size(); i++){
        pq.push({distan(d, sp[i]), i});
        while(pq.size() > K)pq.pop();
    }
    data dd;
    map <int, int> ham;
    int mx = 0, ans = 0;
    int h = 0;
    while(!pq.empty()){
        dd = sp[pq.top().second];
        pq.pop();

        ham[(int)dd.col[N - 1]]++;

    }

    for( map<int,int>::iterator it = ham.begin(); it != ham.end(); it++){
        if(mx < it -> second){
            mx = it -> second;
            ans = it -> first;
        }

    }
    return ans;
}

int res[2][2];


int main(){


    //cout << "Enter the value of K?"<< "\n";
    //cin >> K;
    //cout << endl ;






    double accuracy=0.0;

    double averageAccuracy=0.0;

    double sum=0.0;

    for(int j=0;j<10;j++)
    {
        int correct = 0;
        readFile();

        for(int i = 0; i < ns.size(); i++){
            data d;
            d = ns[i];
           // cout << "Test Data No : " << i + 1 << "\n";
            int result = KNN(d);
            if(result == (int)d.col[N - 1])correct++;
           // cout << " Decision Result : " << result << endl;

            // "1 is for ham sms and 0 is for spam sms"<< endl;
           // cout << "Actual Answer: " << d.col[N - 1] << endl;
           // cout << "\n";
            if(classifier == 2)res[result][(int) d.col[N - 1]]++;


    //cout << "Total Correct result : " << correct << endl;
    //cout << v1.size()<< endl;
        accuracy = ((double)(correct)/(double)ns.size());
        //cout << "Accuracy for testing " << j+1 << "=" << accuracy<< endl;

        sum=sum+accuracy;

        // myvector.erase (myvector.begin(),myvector.begin()+3);
         ns.erase(ns.begin(),ns.begin()+ns.size());

    }

    //cout << sum <<endl;
    }
    averageAccuracy=(sum)/10.0;
    cout << "Average Accuracy is :" << averageAccuracy*100 <<"%" << endl;

    }






