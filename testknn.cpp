#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int cc = 30;
int N;
int K;

#define columnSize 23

struct data{
    double col[cc];

};
/*void printDouble(double d){
    cout << fixed << setprecision(6) << d << endl;
}*/

vector <data> v, v1;

void clearString(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ',')s[i] = ' ';
    }
}
int classes;

void readFile(){

    srand(time(NULL));

    ifstream f("out2.txt");
    string s;

    N = 1;

    map <int, int> deci, cnt;

    while(getline(f, s)){
        clearString(s);
        istringstream iss(s);
        int cnt = 0;
        double d;
        data dd;
        while(iss >> d){

            dd.col[cnt++] = d;

        }
        deci[ (int)dd.col[N - 1]]++;

        v1.push_back(dd);
    }
    int trainData = 0;
    classes = deci.size();

    for( map<int,int>::iterator it = deci.begin(); it != deci.end(); it++){
        cnt[it -> first] = it -> second * 9;
        cnt[it -> first] /= 10;

        trainData += cnt[it -> first];
    }

    cout << "Total Size: " << v1.size() << endl;

    while(true){
        if(!trainData)break;
        int val = rand() % v1.size();

        if(cnt[(int)v1[val].col[N - 1]]){
            v.push_back(v1[val]);
            cnt[(int)v1[val].col[N - 1]]--;
            v1.erase(v1.begin() + val);
            trainData--;
        }
    }


}

double dist(data d1, data d2){
    double d = 0.0;
    for(int j = 0; j < columnSize; j++){
        d += (d1.col[j] - d2.col[j]) * (d1.col[j] - d2.col[j]) * 1.0;
    }
    return d;
}

int KNN(data d){
    priority_queue <pair <double, int> , vector < pair <double, int> >, greater < pair <double, int> > > pq;
    for(int i = 0; i < v.size(); i++){
        pq.push({dist(d, v[i]), i});
        while(pq.size() > K)pq.pop();
    }
    data dd;
    map <int, int> cnt;
    int mx = 0, ans = 0;
    int cc = 0;
    while(!pq.empty()){
        dd = v[pq.top().second];
        pq.pop();

        cnt[(int)dd.col[N - 1]]++;

    }

    for( map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++){
        if(mx < it -> second){
            mx = it -> second;
            ans = it -> first;
        }

    }
    return ans;
}
int res[2][2];
int main(){
    readFile();

    cout << "Enter the value of K?"<< "\n";
    cin >> K;



    cout << "Number of training data:" << v.size() << endl;

    int correct = 0;
    for(int i = 0; i < v1.size(); i++){
        data d;
        d = v1[i];
        cout << "Test Data No : " << i + 1 << "\n";
        int result = KNN(d);
        if(result == (int)d.col[N - 1])correct++;
        cout << " Decision Result : " << result << endl;
        cout << "Actual Answer: " << d.col[N - 1] << endl;
        cout << "-----------------------------------\n";
        if(classes == 2)res[result][(int) d.col[N - 1]]++;

    }
    cout << "Total Test Data: " << v1.size() << endl;
    cout << "Total Correct : " << correct << endl;


}



