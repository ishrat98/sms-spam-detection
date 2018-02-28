#include<iostream>
#include<cmath>
#include<functional>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

struct Point
{
    int classification;     
    double x, y;     
    double distance; 
};



bool comparison(Point a, Point b)
{
    return (a.distance < b.distance);
}

int classifyAPoint(Point data[], int n, int k, Point p)
{
    
    for (int i = 0; i < n; i++)
        data[i].distance =
            sqrt((data[i].x - p.x) * (data[i].x - p.x) +
                 (data[i].y - p.y) * (data[i].y - p.y));

  
    sort(data, data+n, comparison);

    
    
    int freq1 = 0;     // Frequency of classification A
    int freq2 = 0;     // Frequency of classification B
    for (int i = 0; i < k; i++)
    {
        if (data[i].classification == 0)
            freq1++;
        else if (data[i].classification == 1)
            freq2++;
    }

    return (freq1 > freq2 ? 0 : 1);
}

int main()
{
    int n;
    
	ifstream iFile;
    iFile.open("kn.txt");
  //  if(iFile.is_open()) cout << 'k';
	iFile>>n;
	
	Point data[n];
	
   // cout << n;
    int a;
    double b,c;
    
   

    for(int i=0; i<n; i++){
        iFile >> a >> b >>c;
        data[i].classification=a;
        data[i].x=b;
        data[i].y=c;
        
    }
   // cout << n << endl;
    
    
   /* for(int i=0; i<n; i++){
        
        cout <<data[i].classification << endl;
        cout <<data[i].x <<endl;
        cout <<data[i].y << endl;
     }*/
        
        
        
         Point p;
    p.x = 2.5;
    p.y = 7;

   
    int k = 1;
    printf ("The value classified to that point"
            " is %d.\n", classifyAPoint(data, n, k, p));
    return 0;
 
    
    }

    
    
    
    
    


